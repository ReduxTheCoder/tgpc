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
 * File: <file_utils.h>
 * Description: <utils for files and dirs>
*/
# ifndef FILE_UTILS_H
# define FILE_UTILS_H

# include "struct.h"

int dir_exists(const char * path, const int create);
char * build_project_path(const char * project_name);
int create_project(const ProgramConfig * config);
int run_project();

# endif
