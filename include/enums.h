# ifndef ENUMS_H
# define ENUMS_H

typedef enum {
    SUCCESS = 0,
    DENY = 1,
    NOT_ENOUGH_ARGS = 2,
} Error;

typedef enum {
    PYTHON,
    RUST,
    C,
    CPP,
    JAVA,
    INVALID,
} ProgrammingLanguage;

typedef enum {
    LOG_WARN,
    LOG_ERR,
} LogLevel;

# endif
