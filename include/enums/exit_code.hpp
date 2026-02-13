#ifndef EXIT_CODE_HPP
#define EXIT_CODE_HPP

#include <exception>
#include <string>

enum class ExitCode {
    SUCCESS,
    USER_DENIED,
    INCORRECT_PROGRAM_USAGE,
    UNKNOWN_COMMAND,
    INTERNAL_PROGRAM_ERROR,
    ITEM_EXISTS,
    METADATA_NOT_FOUND
};

struct ExitCodeException : public std::exception {
    ExitCode code;
    std::string message;
    
    ExitCodeException(ExitCode c, std::string msg = "") : code(c), message(std::move(msg)) {}

    const char *what() const noexcept override {
        return message.empty() ? "ExitCodeException occurred" : message.c_str();
    }
};

#endif
