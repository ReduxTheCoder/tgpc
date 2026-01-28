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

    return INVALID;
}
