#ifndef EXIT_CODE_HPP
#define EXIT_CODE_HPP

#include <exception>

enum class ExitCode {
    SUCCESS,
    USER_DENIED,
    INCORRECT_PROGRAM_USAGE,
    UNKNOWN_COMMAND,
};

struct ExitCodeException : public std::exception {
    ExitCode code;
    ExitCodeException(ExitCode c) : code(c) {}
};

#endif
