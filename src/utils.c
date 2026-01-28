# include <limits.h>
# include "utils.h"

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
