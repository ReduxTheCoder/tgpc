#include "classes/compile_template.hpp"
#include "enums/exit_code.hpp"

void CompileTemplate::populate_template() {
    switch (ProgrammingLang) {
    case ProgrammingLanguage::PYTHON:
        Template = "python";
        TemplateArgs = {"main.py"};
        break;
    case ProgrammingLanguage::C:
        Template = "gcc";
        TemplateArgs = {"main.c", "-o", "app"};
        break;
    case ProgrammingLanguage::CPP:
        Template = "g++";
        TemplateArgs = {"main.cpp", "-o", "app"};
        break;
    case ProgrammingLanguage::RUST:
        Template = "cargo";
        TemplateArgs = {"run"};
        break;
    case ProgrammingLanguage::JAVA:
        Template = "javac";
        TemplateArgs = {"Main"};
        break;
    case ProgrammingLanguage::JS:
        Template = "console.log(\"Hello, World!\");";
        break;
    case ProgrammingLanguage::TS:
        Template = "console.log(\"Hello, World!\");";
        break;
    case ProgrammingLanguage::RB:
        Template = "puts \"Hello, World!\"";
        break;
    case ProgrammingLanguage::GO:
        Template = "package main\nimport \"fmt\"\nfunc main() "
                   "{\n\tfmt.Println(\"Hello, World!\")\n}";
        break;
    case ProgrammingLanguage::PHP:
        Template = "<?php\n echo \"Hello, World!\\n\";\n?>";
        break;
    default:
        throw ExitCodeException(ExitCode::INCORRECT_PROGRAM_USAGE,
                                "Unknown programming language.");
    }
}
