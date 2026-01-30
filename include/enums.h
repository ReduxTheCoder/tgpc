# ifndef ENUMS_H
# define ENUMS_H

typedef enum {
    SUCCESS = 0,
    DENY = 1,
    NOT_ENOUGH_ARGS = 2,
    INTERNAL_PROGRAM_ERR = 3,
    ITEM_NONEXISTENT = 4,
    ITEM_NOT_DIR = 5,
    ITEM_NOT_FILE = 6,
} ExitCode;

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
