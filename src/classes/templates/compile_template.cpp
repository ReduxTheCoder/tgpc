#include "classes/templates/compile_template.hpp"
#include "enums/exit_code.hpp"
#include "enums/programming_language.hpp"

void CompileTemplate::populate_template() {
    switch (ProgrammingLang) {
    case ProgrammingLanguage::C:
        Template = "gcc";
        TemplateArgs = {"main.c", "-o", "app"};
        break;
    case ProgrammingLanguage::CPP:
        // Template = "g++";
        // TemplateArgs = {"main.cpp", "-o", "app"};
        Template = "make";
        TemplateArgs = {"install"};
        break;
    case ProgrammingLanguage::RUST:
        Template = "cargo";
        TemplateArgs = {"build"};
        break;
    case ProgrammingLanguage::JAVA:
        Template = "javac";
        TemplateArgs = {"Main"};
        break;
    case ProgrammingLanguage::TS:
        Template = "tsc";
        TemplateArgs = {"program.ts"};
        break;
    case ProgrammingLanguage::GO:
        Template = "go";
        TemplateArgs = {"build", "-o", "program", "program.go"};
        break;
    case ProgrammingLanguage::UNKNOWN:
        throw ExitCodeException(ExitCode::INCORRECT_PROGRAM_USAGE,
                                "Unknown programming language.");
    default:
        throw ExitCodeException(
            ExitCode::INCOMPILABLE_PROGRAMMING_LANGUAGE,
            "This programming language is interpeted, could'nt compile");
        break;
    }
}
