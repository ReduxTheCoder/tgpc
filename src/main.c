# include <stdio.h>
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

int main(int argc, char ** argv) {
    ProgramConfig config;

    printf("%s\n%s\n", config.ProjectName, config.ProjectLang);

    int exit_code = build_program_config(argc, argv, &config);

    switch (exit_code) {
        case SUCCESS:
            break;
        case NOT_ENOUGH_ARGS:
            printf("Not enough arguments\n");
            return exit_code;
    }

    printf("%s\n%s\n", config.ProjectName, config.ProjectLang);

    return 1;
}
