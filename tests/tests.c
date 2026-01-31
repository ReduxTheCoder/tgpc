# include <assert.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../include/tests.h"
# include "../include/enums.h"
# include "../include/logging.h"
# include "../include/utils.h"

int test_concat_str() {
    int successes = 0;

    char * res = concat_str("foo", "bar", 0);
    if (strcmp(res, "foo/bar") == 0) {
        successes++;
        plog(LOG_GREAT, "concat_str() directory test PASSED! ");
    } else {
        plog(LOG_ERR, "concat_str() test FAILED! ");
    }

    plog(LOG_WARN, "(%d/2)\n", successes);

    free(res);

    res = concat_str("bar", "foo", 1);
    if (strcmp(res, "barfoo") == 0) {
        successes++;
        plog(LOG_GREAT, "concat_str() test PASSED! ");
    } else {
        plog(LOG_ERR, "concat_str() test FAILED! ");
    }

    plog(LOG_WARN, "(%d/2)\n", successes);

    free(res);

    return successes;
}

int test_get_language_enum_from_str() {
    ProgrammingLanguage lang = get_language_enum_from_str("cpp");
    int successes = 0;

    if (lang == CPP) {
        successes++;
        plog(LOG_GREAT, "get_language_enum_from_str() test PASSED! ");
    } else {
        plog(LOG_ERR, "get_language_enum_from_str() test FAILED! ");
    }

    plog(LOG_WARN, "(%d/2)\n", successes);

    lang = get_language_enum_from_str("py");

    if (lang == PYTHON) {
        successes++;
        plog(LOG_GREAT, "get_language_enum_from_str() test PASSED! ");
    } else {
        plog(LOG_ERR, "get_language_enum_from_str() test FAILED! ");
    }

    plog(LOG_WARN, "(%d/2)\n", successes);

    return successes;
}

int test_get_enum_config_from_str() {
    ConfigFile res;
    int successes = 0;
    
    res = get_enum_config_from_str("run");

    if (res == CONFIG_RUN) {
        successes++;
        plog(LOG_GREAT, "get_enum_config_from_str() test PASSED! ");
    } else {
        plog(LOG_ERR, "get_enum_config_from_str() test FAILED! ");
    }

    plog(LOG_WARN, "(%d/2)\n", successes);

    return successes;
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

    plog(LOG_WARN, "FINAL JUDGEMENT...\n");
    sleep(2);
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















