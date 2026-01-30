#include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "../include/config.h"
# include "../include/file_utils.h"
# include "../include/utils.h"

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

char * get_run_by_config(const char * programming_lang) {
    char * config_path = build_config_path();
    char * config_run_template_path = concat_str(config_path, "run_template.tgpc", 0);
    free(config_path);

    FILE *run_template_file = fopen(config_run_template_path, "r+");
    if (!run_template_file)
        run_template_file = fopen(config_run_template_path, "w+");

    if (!run_template_file)
        return NULL;

    free(config_run_template_path);

    char buf[64];
    char * result = NULL;

    size_t lang_len = strlen(programming_lang);

    while (fgets(buf, sizeof(buf), run_template_file)) {
        if (strncmp(buf, programming_lang, lang_len) != 0) {
            continue;
        }
        if (buf[lang_len] != ':' || buf[lang_len + 1] != ' ') {
            continue;
        }

       char *cmd = buf + lang_len + 2;

        size_t len = strlen(cmd);
        if (len && cmd[len - 1] == '\n')
            cmd[len - 1] = '\0';

        result = strdup(cmd);
        break;
    }

    fclose(run_template_file);
    return result;
}

