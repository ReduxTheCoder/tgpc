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
 * File: <config.c>
 * Description: <Functionality for configs>
*/
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
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

char * get_run_cmd_by_config(const char * programming_lang) {
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

int configure_config(const ConfigParams * params) {
    char * config_dir_path = build_config_path();
    char * config_file_path = NULL;

    switch (params->ConfigFilePath) {
        case CONFIG_RUN:
            config_file_path = concat_str(config_dir_path, "run_template.tgpc", 0);
            break;
        default:
            free(config_dir_path);
            return INTERNAL_PROGRAM_ERR;
    }

    free(config_dir_path);

    FILE * in = fopen(config_file_path, "r");
    char tmp_path[PATH_MAX];
    snprintf(tmp_path, sizeof(tmp_path), "%s.tmp", config_file_path);

    FILE * out = fopen(tmp_path, "w");
    if (!out) {
        free(config_file_path);
        if (in) fclose(in);
        return INTERNAL_PROGRAM_ERR;
    }

    size_t lang_len = strlen(params->ConfigLang);
    char buf[512];
    int found = 0;

    if (in) {
        while (fgets(buf, sizeof(buf), in)) {
            if (
                strncmp(buf, params->ConfigLang, lang_len) == 0 &&
                buf[lang_len] == ':' &&
                buf[lang_len + 1] == ' '
            ) {
                found = 1;
                continue;
            }

            fputs(buf, out);
        }

        fclose(in);
    }

    fprintf(out, "%s: %s\n", params->ConfigLang, params->Command);

    fclose(out);

    rename(tmp_path, config_file_path);
    free(config_file_path);

    return SUCCESS;
}

int show_config(ConfigFile config_file_name) {
    char * config_dir_path = build_config_path();
    char * config_file_path = NULL;

    switch (config_file_name) {
        case CONFIG_RUN:
            config_file_path = concat_str(config_dir_path, "run_template.tgpc", 0);
            break;
        default:
            free(config_dir_path);
            return INTERNAL_PROGRAM_ERR;
    }

    free(config_dir_path);

    FILE * in = fopen(config_file_path, "r");

    char buf[512];

    if (in) {
        while (fgets(buf, sizeof(buf), in)) {
            fputs(buf, stdout);
        }

        fclose(in);
    }

    free(config_file_path);

    return SUCCESS;
}















