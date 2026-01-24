# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include "../include/struct.h"

typedef char * path;

char * build_project_path(const char * project_name) {
    char cwd[PATH_MAX];

    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        return NULL;
    }

    // (+ 2 is for the null terminators)
    size_t len = strlen(cwd) + strlen(project_name) + 2;
    
    char * result = malloc(len);
    
    if (!result) {
        perror("malloc");
        return NULL;
    }
    
    snprintf(result, len, "%s/%s", cwd, project_name);
    return result;
}

void create_project(const ProgramConfig * config) {
    path project_parent = build_project_path(config->ProjectName);
    mkdir(project_parent, 0777);
    free(project_parent);
}
