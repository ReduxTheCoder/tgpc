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
 * File: <struct.c>
 * Description: <Functionality for structs>
 */
#include "../include/struct.h"
#include "../include/logging.h"
#include "../include/utils.h"
#include <stdbool.h>

/*
 * This function builds the ProgramConfig given a pointer of one
 *
 * argc - the number of arguments
 * argv - the table of arguments
 * config - the pointer to a ProgramConfig variable
 * returns an exit code
 */
int build_program_config(int argc, char **argv, ProgramConfig *config) {
	bool error = false;

	if (argc < 3) {
		plog(LOG_ERR, "Project name wasn't given\n");
		error = true;
	}
	if (argc < 4) {
		plog(LOG_ERR, "Project programming language wasn't given\n");
		error = true;
	}

	if (error) {
		return NOT_ENOUGH_ARGS;
	}

	config->ProjectName = argv[2];
	config->ProjectLang = get_language_enum_from_str(argv[3]);
	config->ProgrammingLanguageString = argv[3];

	return SUCCESS;
}

/*
 * This function builds the ConfigParam given a pointer of one
 *
 * argc - the number of arguments
 * argv - the table of arguments
 * config - the pointer to a ConfigParams variable
 * returns an exit code
 */
int build_config_params(int argc, char **argv, ConfigParams *params) {
	bool error = false;

	if (argc < 3) {
		plog(LOG_ERR, "Command wasn't given\n");
		error = true;
	}

	params->ConfigCommand = get_enum_config_cmd_from_str(argv[2]);

	if (argc < 4) {
		plog(LOG_ERR, "Target config wasn't given\n");
		error = true;
	}

	params->ConfigFilePath = get_enum_config_from_str(argv[3]);

	if (params->ConfigCommand == CONFIG_SHOW) {
		return SUCCESS;
	}

	if (argc < 5) {
		plog(LOG_ERR, "Target config language wasn't given\n");
		error = true;
	}
	if (argc < 6) {
		plog(LOG_ERR, "Target config command wasn't given\n");
		error = true;
	}

	if (error) {
		return NOT_ENOUGH_ARGS;
	}

	params->ConfigLang = argv[4];
	params->Command = argv[5];

	return SUCCESS;
}
