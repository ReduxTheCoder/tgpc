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
 * File: <config.h>
 * Description: <Functionality for configs>
*/
# ifndef CONFIG_H
# define CONFIG_H

# include "../include/enums.h"
# include "../include/struct.h"

char * get_run_cmd_by_config(const char * programming_lang);
int configure_config(const ConfigParams * params);
int show_config(ConfigFile config_file_name);

# endif
