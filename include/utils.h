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
 * File: <utils.h>
*/
# ifndef UTILS_H
# define UTILS_H

# include "../include/enums.h"

char * concat_str(const char * str1, const char * str2, const int is_path);
ProgrammingLanguage get_language_enum_from_str(const char * lang);
ConfigFile get_enum_config_from_str(const char * config_name);
ConfigCmd get_enum_config_cmd_from_str(const char * cmd);

# endif
