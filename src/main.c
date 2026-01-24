# include <stdio.h>
# include <string.h>
# include "../include/enums.h"

typedef struct {
    char * ProjectName;
    char * ProjectLang;
} ProgramConfig;

/*
 * This function builds the ProgramConfig given a pointer of one
 *
 * argc - the number of arguments
 * argv - the table of arguments
 * config - the pointer to a ProgramConfig variable
 * returns an exit code
*/
int build_program_config(int argc, char ** argv, ProgramConfig * config) {
    if (argc < 3) {
        return NOT_ENOUGH_ARGS;
    }

    config->ProjectName = argv[1];
    config->ProjectLang = argv[2];

    return SUCCESS;
}

void display_help_message() {
    printf("TGPC - The Greatest Project Creator (v0.1)\n");
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

    int exit_code = build_program_config(argc, argv, &config);

    switch (exit_code) {
        case SUCCESS:
            break;
        case NOT_ENOUGH_ARGS:
            display_help_message();
            return exit_code;
    }

    return SUCCESS;
}
