# include <stdio.h>
# include <string.h>
# include "../include/file_utils.h"
# include "../include/enums.h"
# include "../include/struct.h"

# define PROGRAM_VER 0.3

/*
 * This function converts the programming language string into an enum
 * from ../include/enums.h
 *
 * lang - the programming language string given by the user
 * returns the ProgrammingLanguage enum
*/
ProgrammingLanguage get_language_enum(const char * lang) {
    if (strcmp(lang, "c") == 0) {
        return C;
    }
    if (strcmp(lang, "cpp") == 0) {
        return CPP;
    }
    if (strcmp(lang, "py") == 0) {
        return PYTHON;
    }
    if (strcmp(lang, "java") == 0) {
        return JAVA;
    }
    if (strcmp(lang, "rs") == 0) {
        return RUST;
    }

    return INVALID;
}

/*
 * This function builds the ProgramConfig given a pointer of one
 *
 * argc - the number of arguments
 * argv - the table of arguments
 * config - the pointer to a ProgramConfig variable
 * returns an exit code
*/
int build_program_config(int argc, char ** argv, ProgramConfig * config) {
    if (argc < 4) {
        return NOT_ENOUGH_ARGS;
    }

    config->ProjectName = argv[2];
    config->ProjectLang = get_language_enum(argv[3]);
    config->ProgrammingLanguageString = argv[3];

    return SUCCESS;
}

void display_help_message() {
    printf("TGPC - The Greatest Project Creator (%f)\n", PROGRAM_VER);
    printf("A C CLI tool to quickly scaffold code projects using templates.\n\n");

    printf("Usage:\n");
    printf("  tgpc [COMMAND] [ARGS]\n\n");

    printf("Commands:\n");
    printf("  new, n <NAME> <LANG>   Create a new project with a given name and programming language\n");
    printf("  help, h                Display this help message\n\n");

    printf("Examples:\n");
    printf("  tgpc new my-project py\n");
    printf("  tgpc help\n");
}

int main(int argc, char ** argv) {
    ProgramConfig config;

    if (strcmp("new", argv[1]) == 0 || strcmp("n", argv[1]) == 0) {
        int exit_code = build_program_config(argc, argv, &config);

        switch (exit_code) {
            case SUCCESS:
                create_project(&config);
                break;
            case NOT_ENOUGH_ARGS:
                display_help_message();
                return exit_code;
        }
    }
    else if (strcmp("help", argv[1]) == 0 || strcmp("h", argv[1]) == 0) {
        display_help_message();
        return 1;
    }

    return SUCCESS;
}
