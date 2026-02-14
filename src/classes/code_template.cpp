#include "classes/code_template.hpp"
#include "enums/exit_code.hpp"

std::string CodeTemplate::get_main_template_from_programming_language() const {
	switch (ProgrammingLang) {
	case ProgrammingLanguage::PYTHON:
		return "print(\"Hello, World!\")";
	case ProgrammingLanguage::C:
		return "#include <stdio.h>\n\nint main(int argc, const char **argv) "
		       "{\n\tprintf(\"Hello, World!\");\nreturn 0;\n}";
	case ProgrammingLanguage::CPP:
		return "#include <iostream>\n\nint main(int argc, const char **argv) "
		       "{\n\tstd::cout << \"Hello, World!\\n\";\n\treturn 0;\n}";
	case ProgrammingLanguage::RUST:
		return "fn main() {\n\tprintln!(\"Hello, World!\");\n}";
	case ProgrammingLanguage::JAVA:
		return "public class Main {\n\tpublic static void main(String[] args) "
		       "{\n\t\tSystem.out.println(\"Hello, World!\");\n\t}\n}";
	case ProgrammingLanguage::ASM:
		return "global _start\nsection .text\n_start:\n\tmov rax, 60\n\tmov "
		       "rdi, 0\n\tsyscall";
	case ProgrammingLanguage::JS:
		return "console.log(\"Hello, World!\");";
	case ProgrammingLanguage::TS:
		return "console.log(\"Hello, World!\");";
	case ProgrammingLanguage::RB:
		return "puts \"Hello, World!\"";
	case ProgrammingLanguage::GO:
		return "package main\nimport \"fmt\"\nfunc main() "
		       "{\n\tfmt.Println(\"Hello, World!\")\n}";
	case ProgrammingLanguage::PHP:
		return "<?php\n echo \"Hello, World!\\n\";\n?>";
	default:
		throw ExitCodeException(ExitCode::INCORRECT_PROGRAM_USAGE,
		                        "Unknown programming language.");
	}
}

const std::string &CodeTemplate::get_template() const { return Template; }
