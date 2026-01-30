# include <stdio.h>
# include <stdarg.h>
# include "../include/logging.h"
# include "../include/enums.h"

# define ANSI_RED "\033[31m"
# define ANSI_YELLOW "\033[33m"
# define ANSI_RST "\033[0m"

void plog(const LogLevel log_level, const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);

    switch (log_level) {
        case LOG_ERR:
            printf(ANSI_RED "[ERROR]: " ANSI_RST);
            vprintf(fmt, args);
            break;
        case LOG_WARN:
            printf(ANSI_YELLOW "[WARNING]: " ANSI_RST);
            vprintf(fmt, args);
            break;
        default:
            printf("[LOG]: ");
            vprintf(fmt, args);
            break;
    }

    va_end(args);
}
