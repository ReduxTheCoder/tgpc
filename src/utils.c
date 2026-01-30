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
 * File: <utils.c>
*/
# include <limits.h>
# include "utils.h"
# include "../include/enums.h"

char * concat_str(const char * str1, const char * str2, const int is_path) {
    // (+ 2 is for the null terminators)
    size_t len = strlen(str1) + strlen(str2) + 2;
    
    char * result = malloc(len);
    
    if (!result) {
        perror("malloc");
        return NULL;
    }
    
    if (is_path == 0) {
        snprintf(result, len, "%s/%s", str1, str2);
    } else {
        snprintf(result, len, "%s%s", str1, str2);
    }
    return result;
}

ProgrammingLanguage get_language_enum(const char * lang) {
    if (strcmp(lang, "c") == 0) {
        return C;
    }
    if (strcmp(lang, "cpp") == 0) {
        return CPP;
    }
    if (strcmp(lang, "py") == 0) {
        return PYTHON;
    }
    if (strcmp(lang, "java") == 0) {
        return JAVA;
    }
    if (strcmp(lang, "rs") == 0) {
        return RUST;
    }
    if (strcmp(lang, "asm") == 0) {
        return ASM;
    }
    if (strcmp(lang, "js") == 0) {
        return JS;
    }
    if (strcmp(lang, "ts") == 0) {
        return TS;
    }
    if (strcmp(lang, "rb") == 0) {
        return RB;
    }
    if (strcmp(lang, "go") == 0) {
        return GO;
    }
    if (strcmp(lang, "php") == 0) {
        return PHP;
    }

    return INVALID;
}
