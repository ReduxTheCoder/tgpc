
/*
 * TGPC - Command-line project scaffolder
 * Copyright (c) 2026 ReduxTheCoder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * File: <main.c>
*/
# include <stdio.h>
# include <string.h>
# include "../include/file_utils.h"
# include "../include/enums.h"
# include "../include/struct.h"
# include "../include/utils.h"

# define PROGRAM_VER "1.1.2"

/*
 * this function converts the programming language string into an enum
 * from ../include/enums.h
 *
 * lang - the programming language string given by the user
 * returns the programminglanguage enum
*/

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
    printf("TGPC - The Greatest Project Creator (%s)\n", PROGRAM_VER);
    printf("A C CLI tool to quickly scaffold code projects using templates.\n\n");

    printf("Usage:\n");
    printf("  tgpc [COMMAND] [ARGS]\n\n");

    printf("Commands:\n");
    printf("  new, n <NAME> <LANG>   Create a new project with a given name and programming language\n");
    printf("  help, h                Display this help message\n");
    printf("  run, r                 Run the project in the current working directory\n\n");

    printf("Examples:\n");
    printf("  tgpc new my-project py\n");
    printf("  tgpc run\n");
    printf("  tgpc help\n");
}

int main(int argc, char ** argv) {
    ProgramConfig config;

    if (strcmp("new", argv[1]) == 0 || strcmp("n", argv[1]) == 0) {
        int exit_code = build_program_config(argc, argv, &config);

        switch (exit_code) {
            case SUCCESS:
                return create_project(&config);
            case NOT_ENOUGH_ARGS:
                display_help_message();
                return exit_code;
        }
    }
    else if (strcmp("help", argv[1]) == 0 || strcmp("h", argv[1]) == 0) {
        display_help_message();
    }
    else if (strcmp("run", argv[1]) == 0 || strcmp("r", argv[1]) == 0) {
        return run_project();
    }

    return SUCCESS;
}
