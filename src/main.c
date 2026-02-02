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
#include "../include/config.h"
#include "../include/enums.h"
#include "../include/file_utils.h"
#include "../include/logging.h"
#include "../include/struct.h"
#include "../include/utils.h"
#include "../include/version.h"
#include <stdbool.h>
#include <stdio.h>

#ifndef TESTING

void display_help_message() {
	printf("TGPC - The Greatest Project Creator (%s)\n", PROGRAM_VER);
	printf(
	    "A C CLI tool to quickly scaffold code projects using templates.\n\n");

	printf("Usage:\n");
	printf("└─● tgpc [COMMAND] [ARGS]\n\n");

	printf("Commands:\n");
	printf("├─● new, n <NAME> <LANG>                               Create a "
	       "new project with a given name and programming language\n");
	printf("├─● help, h                                            Display "
	       "this help message\n");
	printf("├─● run, r                                             Run the "
	       "project in the current working directory\n");
	printf("├─● data, d                                            Print the "
	       "current project's data\n");
	printf("└─● config, c <COMMAND>                                Interact "
	       "with configuration files\n");
	printf("      set, w  <CONFIG_NAME> <LANG> <RUN_CMD>\n");
	printf("      show, s  <CONFIG_NAME>\n\n");

	printf("Languages:\n");
	printf("  - py\n  - rs\n  - c\n  - cpp\n  - java\n  - asm\n  - js\n  - "
	       "ts\n  - rb\n  - go\n  - php\n\n");

	printf("Config names:\n");
	printf("└─● run\n\n");

	printf("Examples:\n");
	printf("├─● tgpc new my-project py\n");
	printf("├─● tgpc run\n");
	printf("├─● tgpc help\n");
	printf("├─● tgpc data\n");
	printf("├─● tgpc config set run py \"python3 main.py\"\n");
	printf("└─● tgpc config show run\n");
}

int main(int argc, char **argv) {
	if (argc < 2) {
		display_help_message();
		return SUCCESS;
	}

	TgpcCommand command = get_tgpc_command_from_str(argv[1]);

	switch (command) {
	case COMMAND_NEW: {
		ProgramConfig config;
		int exit_code = build_program_config(argc, argv, &config);

		switch (exit_code) {
		case SUCCESS:
			return create_project(&config);
		case NOT_ENOUGH_ARGS:
			display_help_message();
			return exit_code;
		}
		return SUCCESS;
	}

	case COMMAND_HELP:
		display_help_message();
		return SUCCESS;

	case COMMAND_RUN:
		return run_project();

	case COMMAND_CONFIG: {
		ConfigParams params;
		int exit_code_config = build_config_params(argc, argv, &params);

		switch (exit_code_config) {
		case SUCCESS:
			if (params.ConfigCommand == CONFIG_SHOW) {
				return show_config(params.ConfigFilePath);
			} else {
				return configure_config(&params);
			}
		case NOT_ENOUGH_ARGS:
			display_help_message();
			return exit_code_config;
		}
		return INTERNAL_PROGRAM_ERR;
	}

	case COMMAND_DATA:
		return show_project_metadata();

    case COMMAND_UPDATE:
        return update_project_metadata();

	case COMMAND_UNKNOWN:
		plog(LOG_ERR, "Unknown command '%s'\n", argv[1]);
		return INCORRECT_USAGE;

	default:
		plog(LOG_ERR, "Internal Program Error\n");
		return INTERNAL_PROGRAM_ERR;
	}

	return SUCCESS;
	// if (strcmp("new", argv[1]) == 0 || strcmp("n", argv[1]) == 0) {
	//     ProgramConfig config;
	//     int exit_code = build_program_config(argc, argv, &config);
	//
	//     switch (exit_code) {
	//         case SUCCESS:
	//             return create_project(&config);
	//         case NOT_ENOUGH_ARGS:
	//             display_help_message();
	//             return exit_code;
	//     }
	// }
	// else if (strcmp("help", argv[1]) == 0 || strcmp("h", argv[1]) == 0) {
	//     display_help_message();
	// }
	// else if (strcmp("run", argv[1]) == 0 || strcmp("r", argv[1]) == 0) {
	//     return run_project();
	// }
	// else if (strcmp("config", argv[1]) == 0 || strcmp("c", argv[1]) == 0) {
	//     ConfigParams params;
	//
	//     int exit_code = build_config_set_params(argc, argv, &params);
	//
	//     switch (exit_code) {
	//         case SUCCESS:
	//             if (params.ConfigCommand == CONFIG_SHOW) {
	//                 return show_config(params.ConfigFilePath);
	//             } else {
	//                 return configure_config(&params);
	//             }
	//         case NOT_ENOUGH_ARGS:
	//             display_help_message();
	//             return exit_code;
	//     }
	// } else {
	//     plog(LOG_ERR, "Unknown command '%s'\n", argv[1]);
	//     return INCORRECT_USAGE;
	// }
}

#endif
