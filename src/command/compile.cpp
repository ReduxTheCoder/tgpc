#include "commands/run.hpp"
#include "classes/code_template.hpp"
#include "enums/exit_code.hpp"
#include "enums/programming_language.hpp"
#include "structs/metadata.hpp"

void run_project(void) {
	std::string programming_language =
	    Metadata::get(Metadata::Key::PROGRAMMING_LANGUAGE);

	ProgrammingLanguage programming_language_enum =
	    get_enum_programming_language_from_string(&programming_language);

    
}
