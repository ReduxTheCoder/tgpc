# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include "../include/struct.h"
# include "../include/utils.h"

typedef char * path;

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
            break;
        case C:
            return "# include <stdio.h>\n\nint main(const int argc, const char ** argv) {\n\tprintf(\"Hello, World\");\n\treturn 0;\n}";
            break;
        case CPP:
            return "# include <iostream>\n\nint main(const int argc, const char ** argv) {\n\tstd::cout << \"Hello, World!\\n\";\n\treturn 0;\n}";
            break;
        case RUST:
            return "fn main() {\n\tprintln!(\"Hello, World!\")\n}";
            break;
        case JAVA:
            return "public class HelloWorld {\\n    public static void main(String[] args) {\\n        System.out.println(\\\"Hello, World!\\\");\\n    }\\n}";
            break;
        default:
            printf("Warning: Language not recognized, this will make an empty template file");
            return "";
            break;
    }
}

void create_project(const ProgramConfig * config) {
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

    char * template_str = get_template_by_lang(config->ProjectLang);

    fprintf(main, "%s\n", template_str);
}
