
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
 * File: <enums.h>
 * Description: <Enums>
*/
# ifndef ENUMS_H
# define ENUMS_H

typedef enum {
    SUCCESS = 0,
    DENY = 1,
    NOT_ENOUGH_ARGS = 2,
    INTERNAL_PROGRAM_ERR = 3,
    ITEM_NONEXISTENT = 4,
    ITEM_NOT_DIR = 5,
    ITEM_NOT_FILE = 6,
    INCORRECT_USAGE = 7,
} ExitCode;

typedef enum {
    C = 0,
    CPP,
    PYTHON,
    JAVA,
    RUST,
    ASM,
    JS,
    TS,
    RB,
    GO,
    PHP,
    INVALID
} ProgrammingLanguage;

typedef enum {
    LOG_WARN,
    LOG_ERR,
    LOG_GREAT,
} LogLevel;

typedef enum {
    CONFIG_RUN,
    NONE,
} ConfigFile;

typedef enum {
    CONFIG_SET,
    CONFIG_SHOW,
} ConfigCmd;

# endif
