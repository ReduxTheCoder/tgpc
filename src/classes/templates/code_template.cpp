#include "classes/templates/code_template.hpp"
#include "enums/exit_code.hpp"

void CodeTemplate::populate_template() {
	switch (ProgrammingLang) {
	case ProgrammingLanguage::PYTHON:
		Template = "print(\"Hello, World!\")";
        break;
	case ProgrammingLanguage::C:
		Template =
		    "#include <stdio.h>\n\nint main(int argc, const char **argv) "
		    "{\n\tprintf(\"Hello, World!\");\nreturn 0;\n}";
        break;
	case ProgrammingLanguage::CPP:
		Template =
		    "#include <iostream>\n\nint main(int argc, const char **argv) "
		    "{\n\tstd::cout << \"Hello, World!\\n\";\n\treturn 0;\n}";
        break;
	case ProgrammingLanguage::RUST:
		Template = "fn main() {\n\tprintln!(\"Hello, World!\");\n}";
        break;
	case ProgrammingLanguage::JAVA:
		Template =
		    "public class Main {\n\tpublic static void main(String[] args) "
		    "{\n\t\tSystem.out.println(\"Hello, World!\");\n\t}\n}";
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
