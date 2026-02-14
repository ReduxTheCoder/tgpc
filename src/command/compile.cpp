#include "classes/compile_template.hpp"
#include "command_executor.hpp"
#include "commands/compile.hpp"
#include "enums/programming_language.hpp"
#include "structs/metadata.hpp"

void run_project(void) {
	std::string programming_language =
	    Metadata::get(Metadata::Key::PROGRAMMING_LANGUAGE);

	ProgrammingLanguage programming_language_enum =
	    get_enum_programming_language_from_string(&programming_language);

    CompileTemplate compile_template(programming_language_enum);
    
    execute_command(compile_template.get_template(), compile_template.get_template_argument());
}
