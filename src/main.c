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
# include "../include/config.h"
# include "../include/file_utils.h"
# include "../include/enums.h"
# include "../include/struct.h"
# include "../include/utils.h"
# include "../include/logging.h"

# define PROGRAM_VER "1.1.2"

# ifndef TESTING

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
    int error = 0;

    if (argc < 3) {
        plog(LOG_ERR, "Project name wasn't given\n");
        error = 1;
    }
    if (argc < 4) {
        plog(LOG_ERR, "Project programming language wasn't given\n");
        error = 1;
    }

    if (error > 0) {
        return NOT_ENOUGH_ARGS;
    }

    config->ProjectName = argv[2];
    config->ProjectLang = get_language_enum_from_str(argv[3]);
    config->ProgrammingLanguageString = argv[3];

    return SUCCESS;
}

int build_config_params(int argc, char ** argv, ConfigParams * config) {
    int error = 0;

    if (argc < 3) {
        plog(LOG_ERR, "Target config wasn't given\n");
        error = 1;
    }
    if (argc < 4) {
        plog(LOG_ERR, "Target config language wasn't given\n");
        error = 1;
    }
    if (argc < 5) {
        plog(LOG_ERR, "Target config command wasn't given\n");
    }

    if (error > 0) {
        return NOT_ENOUGH_ARGS;
    }

    config->ConfigFilePath = get_enum_config_from_str(argv[2]);
    config->ConfigLang = argv[3];
    config->Command = argv[4];

    return SUCCESS;
}

void display_help_message() {
    printf("TGPC - The Greatest Project Creator (%s)\n", PROGRAM_VER);
    printf("A C CLI tool to quickly scaffold code projects using templates.\n\n");

    printf("Usage:\n");
    printf("  tgpc [COMMAND] [ARGS]\n\n");

    printf("Commands:\n");
    printf("  new, n <NAME> <LANG>                              Create a new project with a given name and programming language\n");
    printf("  help, h                                           Display this help message\n");
    printf("  run, r                                            Run the project in the current working directory\n");
    printf("  config, c <CONFIG_NAME> <LANG> <CMD>              Manipulate a config by its name (cmd is the run command)\n\n");

    printf("Languages:\n");
    printf("  - py\n  - rs\n  - c\n  - cpp\n  - java\n  - asm\n  - js\n  - ts\n  - rb\n  - go\n  - php\n\n");
    
    printf("Config names:\n");
    printf("  - run\n\n");

    printf("Examples:\n");
    printf("  tgpc new my-project py\n");
    printf("  tgpc run\n");
    printf("  tgpc help\n");
    printf("  tgpc config run py \"python3 main.py\"\n");
}

int main(int argc, char ** argv) {
    if (!argv[1]) {
        display_help_message();
        return SUCCESS;
    }

    if (strcmp("new", argv[1]) == 0 || strcmp("n", argv[1]) == 0) {
        ProgramConfig config;
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
    else if (strcmp("config", argv[1]) == 0 || strcmp("c", argv[1]) == 0) {
        ConfigParams config;
        int exit_code = build_config_params(argc, argv, &config);

        switch (exit_code) {
            case SUCCESS:
                return configure_config(config.ConfigFilePath, config.ConfigLang, config.Command);
            case NOT_ENOUGH_ARGS:
                display_help_message();
                return exit_code;
        }
    } else {
        plog(LOG_ERR, "Unknown command '%s'\n", argv[1]);
        return INCORRECT_USAGE;
    }

    return SUCCESS;
}

# endif
