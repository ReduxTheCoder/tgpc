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
 * File: <rust_bridge.h>
*/
# pragma once
# include "enums.h"
# include "utils.h"

ProgrammingLanguage get_language_enum_from_str_rust(const char * lang);
ConfigFile get_enum_config_from_str_rust(const char * config);
ConfigCmd get_enum_config_cmd_from_str_rust(const char * cmd);
TgpcCommand get_tgpc_command_from_str_rust(const char * cmd);
