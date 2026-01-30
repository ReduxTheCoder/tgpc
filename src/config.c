# include "../include/config.h"
# include "../include/file_utils.h"
# include <string.h>
# include <stdlib.h>

static char * build_config_path() {
    const char * xdg = getenv("XDG_CONFIG_HOME");
    if (xdg && *xdg) {
        return strdup(xdg);
    }

    const char * home = getenv("HOME");
    if (!home || !*home) {
        return NULL;
    }

    size_t len = strlen(home) + strlen("/.config/tgpc") + 1;
    char * path = malloc(len);
    if (!path) return NULL;

    strcpy(path, home);
    strcat(path, "/.config/tgpc");

    dir_exists(path, 1);

    return path;
}

char * get_run_by_config(const ProgrammingLanguage lang) {
    const char * config_path = build_config_path();
}
