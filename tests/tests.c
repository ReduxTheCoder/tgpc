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
 * File: <tests.c>
*/

# include <assert.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
// # include "../include/tests.h"
# include "../include/config.h"
# include "../include/enums.h"
# include "../include/logging.h"
# include "../include/utils.h"

int test_concat_str() {
    int successes = 0;

    char * res = concat_str("foo", "bar", 0);
    if (strcmp(res, "foo/bar") == 0) {
        successes++;
        plog(LOG_GREAT, "concat_str() directory test PASSED!\n");
    } else {
        plog(LOG_ERR, "concat_str() test FAILED!\n");
    }

    free(res);

    res = concat_str("bar", "foo", 1);
    if (strcmp(res, "barfoo") == 0) {
        successes++;
        plog(LOG_GREAT, "concat_str() test PASSED!\n");
    } else {
        plog(LOG_ERR, "concat_str() test FAILED!\n");
    }

    free(res);

    return successes;
}

int test_get_language_enum_from_str() {
    ProgrammingLanguage lang = get_language_enum_from_str("cpp");
    int successes = 0;

    if (lang == CPP) {
        successes++;
        plog(LOG_GREAT, "get_language_enum_from_str() test PASSED!\n");
    } else {
        plog(LOG_ERR, "get_language_enum_from_str() test FAILED!\n");
    }

    lang = get_language_enum_from_str("py");

    if (lang == PYTHON) {
        successes++;
        plog(LOG_GREAT, "get_language_enum_from_str() test PASSED!\n");
    } else {
        plog(LOG_ERR, "get_language_enum_from_str() test FAILED!\n");
    }

    return successes;
}

int test_get_enum_config_from_str() {
    ConfigFile res;
    int successes = 0;
    
    res = get_enum_config_from_str("run");

    if (res == CONFIG_RUN) {
        successes++;
        plog(LOG_GREAT, "get_enum_config_from_str() test PASSED!\n");
    } else {
        plog(LOG_ERR, "get_enum_config_from_str() test FAILED!\n");
    }

    return successes;
}

int test_build_config_path() {
    int successes = 0;

    char * res = build_config_path();

    if (strcmp(res, "/home/San_Genna/.config/tgpc") == 0) {

    }
}

int main() {
    int total_tests = 0;
    int total_passed = 0;

    int passed;

    plog(4, "Running concat_str() tests...\n");
    passed = test_concat_str();
    total_passed += passed;
    total_tests += 2;
    printf("\n");

    plog(4, "Running get_language_enum_from_str() tests...\n");
    passed = test_get_language_enum_from_str();
    total_passed += passed;
    total_tests += 2;
    printf("\n");

    plog(4, "Running get_enum_config_from_str() tests...\n");
    passed = test_get_enum_config_from_str();
    total_passed += passed;
    total_tests += 1;
    printf("\n");

    if (total_passed == total_tests) {
        plog(LOG_GREAT, "ALL TESTS PASSED!\n");
    } else {
        plog(LOG_ERR, "Some tests failed...\n");
    }
    printf("\n");
    plog(LOG_WARN, "(%d/%d)\n", total_passed, total_tests);
    double ratio = (double)total_passed / total_tests;
    plog(LOG_WARN, "%lf\n", ratio);

    return (total_passed == total_tests) ? 0 : 1;
}















