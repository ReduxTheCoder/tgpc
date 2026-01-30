# ifndef FILE_UTILS_H
# define FILE_UTILS_H

# include "struct.h"

int dir_exists(const char * path, const int create);
char * build_project_path(const char * project_name);
int create_project(const ProgramConfig * config);
int run_project();

# endif
