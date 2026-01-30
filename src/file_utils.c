# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <stdbool.h>
# include "../include/struct.h"
# include "../include/config.h"
# include "../include/logging.h"
# include "../include/utils.h"

typedef char * path;

int dir_exists(const char * path, const int create) {
    struct stat st;
    
    if (stat(path, &st) != 0) {
        if (create > 0) {
            int operation_code = mkdir(path, 0755);

            if (operation_code == -1) {
                return INTERNAL_PROGRAM_ERR;
            }
        } else {
            return ITEM_NONEXISTENT;
        }
    }

    if ((st.st_mode & S_IFDIR) == 0) {
        return ITEM_NOT_DIR;
    }
    
    return SUCCESS;
}

char * build_project_path(const char * project_name) {
    char cwd[PATH_MAX];

    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        return NULL;
    }

    return concat_str(cwd, project_name, 0);
}

static char * get_template_by_lang(const ProgrammingLanguage lang) {
    switch (lang) {
        case PYTHON:
            return "print(\"Hello, World!\")";
        case C:
            return "# include <stdio.h>\n\nint main(const int argc, const char ** argv) {\n\tprintf(\"Hello, World\\n\");\n\treturn 0;\n}";
        case CPP:
            return "# include <iostream>\n\nint main(const int argc, const char ** argv) {\n\tstd::cout << \"Hello, World!\\n\";\n\treturn 0;\n}";
        case RUST:
            return "fn main() {\n\tprintln!(\"Hello, World!\");\n}";
        case JAVA:
            return "public class main {\n\tpublic static void main(String[] args) {\n\t\tSystem.out.println(\"Hello, World!\");\n\t}\n}";
        case ASM:
            return "global _start\nsection .text\n_start:\n\tmov rax, 60\n\tmov rdi, 0\n\tsyscall";
        case JS:
            return "console.log(\"Hello, World!\");";
        case TS:
            return "console.log(\"Hello, World!\");";
        case RB:
            return "puts \"Hello, World!\"";
        case GO:
            return "package main\nimport \"fmt\"\nfunc main() {\n\tfmt.Println(\"Hello, World!\")\n}";
        case PHP:
            return "<?php\n echo \"Hello, World!\\n\";\n?>";
        default: {
            char input[64];
            plog("Language not recognized, this will make an empty template file\nAre you sure of this?\n", LOG_WARN);
            printf("(y/n) ");

            if (fgets(input, sizeof(input), stdin) != NULL && strcmp(input, "y\n") == 0) {
                return "";
            } else {
                return NULL;
            }
        }
    }
}

static char * get_run_by_lang(const char * programming_lang) {
    ProgrammingLanguage lang = get_language_enum(programming_lang);

    char * run_command = get_run_by_config(programming_lang);

    if (run_command) {
        return run_command;
    }

    switch (lang) {
        case PYTHON:
            return strdup("python main.py");
        case C:
            return strdup("gcc main.c -o app && ./app");
        case CPP:
            return strdup("g++ main.cpp -o app && ./app");
        case RUST:
            return strdup("cargo run");
        case JAVA:
            return strdup("javac main.java && java main");
        case ASM:
            return strdup("nasm -f elf64 main.asm -o main.o && gcc main.o -o main && ./main");
        case JS:
            return strdup("node main.js");
        case TS:
            return strdup("tsc main.ts && node main.js");
        case RB:
            return strdup("ruby main.rb");
        case GO:
            return strdup("go run main.go");
        case PHP:
            return strdup("php main.php");
        default:
            return NULL;
    }
}

int create_project(const ProgramConfig * config) {
    switch (config->ProjectLang) {
        case RUST: {
            char * cmd = concat_str("cargo new \"", config->ProjectName, 1);
            char * tmp = concat_str(cmd, "\"", 0);
            system(tmp);
            free(cmd);
            free(tmp);
            return SUCCESS;
        }
        case GO: {
            char * cmd = concat_str("go mod init \"", config->ProjectName, 1);
            char * tmp = concat_str(cmd, "\"", 0);
            system(cmd);
            free(cmd);
            free(tmp);
            return SUCCESS;
        }
        default:
            break;
    }

    char * template_str = get_template_by_lang(config->ProjectLang);

    if (template_str == NULL) {
        return DENY;
    }

    path project_parent = build_project_path(config->ProjectName);
    mkdir(project_parent, 0777);

    chdir(project_parent);
    free(project_parent);

    FILE * metadata = fopen(".tgpc_meta", "a");
    fprintf(metadata, "%s\n", config->ProgrammingLanguageString);
    fclose(metadata);

    char * main_name = concat_str("main.", config->ProgrammingLanguageString, 1);
    FILE * main = fopen(main_name, "a");
    free(main_name);

    fprintf(main, "%s\n", template_str);

    fclose(main);
    return SUCCESS;
}

int run_project() {
    FILE * metadata = fopen(".tgpc_meta", "r");

    if (!metadata) {
        plog("Couldn't find .tgpc_meta file, aborting...\n", LOG_ERR);
        return 4;
    }

    char programming_lang[64];

    fgets(programming_lang, sizeof(programming_lang), metadata);
    programming_lang[strcspn(programming_lang, "\n")] = 0;

    char * cmd = get_run_by_lang(programming_lang);
    if (!cmd) {
        plog("Cannot determine run command for this language\n", LOG_ERR);
        return DENY;
    }

    system(cmd);
    free(cmd);
    return SUCCESS;
}
