#ifndef USER_TEMPLATE_HPP
#define USER_TEMPLATE_HPP

#include "enums/programming_language.hpp"
#include <string>

class CodeTemplate {
	ProgrammingLanguage ProgrammingLang;
	std::string Template;

    public:
	CodeTemplate(ProgrammingLanguage programming_language)
	    : ProgrammingLang(programming_language),
	      Template(get_main_template_from_programming_language()) {}

	std::string get_main_template_from_programming_language() const;
    const std::string& get_template() const;
};

#endif
