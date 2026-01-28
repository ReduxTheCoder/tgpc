# include <stdio.h>
# include "../include/logging.h"
# include "../include/enums.h"

# define ANSI_RED "\033[31m"
# define ANSI_YELLOW "\033[33m"
# define ANSI_RST "\033[0m"

void plog(const char * msg, const LogLevel log_level) {
    switch (log_level) {
        case LOG_ERR:
            printf(ANSI_RED "[ERROR]: %s" ANSI_RST, msg);
            break;
        case LOG_WARN:
            printf(ANSI_YELLOW "[WARNING]: %s" ANSI_RST, msg);
            break;
        default:
            printf("[LOG]: %s", msg);
            break;
    }
}
