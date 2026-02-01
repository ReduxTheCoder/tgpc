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
 * File: <logging.c
 * Description: <Pretty print stuff>
*/
# include <stdio.h>
# include <stdarg.h>
# include "../include/logging.h"
# include "../include/enums.h"

# define ANSI_RED "\033[31m"
# define ANSI_YELLOW "\033[33m"
# define ANSI_GREEN "\033[32m"
# define ANSI_RST "\033[0m"

void plog(const LogLevel log_level, const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);

    switch (log_level) {
        case LOG_GREAT:
            printf(ANSI_GREEN "[GREAT]: " ANSI_RST);
            vprintf(fmt, args);
            break;
        case LOG_ERR:
            printf(ANSI_RED "[ERROR]: " ANSI_RST);
            vprintf(fmt, args);
            break;
        case LOG_WARN:
            printf(ANSI_YELLOW "[WARNING]: " ANSI_RST);
            vprintf(fmt, args);
            break;
        default:
            printf("[LOG]: ");
            vprintf(fmt, args);
            break;
    }

    va_end(args);
}
