#include "enums/programming_language.hpp"
#include "enums/exit_code.hpp"

ProgrammingLanguage get_enum_programming_language_from_string(const std::string *string) {
    if (*string == "py") return ProgrammingLanguage::PYTHON;
    if (*string == "c") return ProgrammingLanguage::C;
    if (*string == "cpp") return ProgrammingLanguage::CPP;
    if (*string == "java") return ProgrammingLanguage::JAVA;
    if (*string == "rs") return ProgrammingLanguage::RUST;
    if (*string == "asm") return ProgrammingLanguage::ASM;
    if (*string == "js") return ProgrammingLanguage::JS;
    if (*string == "ts") return ProgrammingLanguage::TS;
    if (*string == "rb") return ProgrammingLanguage::RB;
    if (*string == "go") return ProgrammingLanguage::GO;
    if (*string == "php") return ProgrammingLanguage::PHP;
    else throw ExitCodeException(ExitCode::INCORRECT_PROGRAM_USAGE);
}
