#ifndef PROGRAMMING_LANGUAGE_HPP
#define PROGRAMMING_LANGUAGE_HPP

#include <string>

enum class ProgrammingLanguage {
	C,
	CPP,
	PYTHON,
	JAVA,
	RUST,
	JS,
	TS,
	RB,
	GO,
	PHP,
	UNKNOWN,
};

ProgrammingLanguage
get_enum_programming_language_from_string(const std::string *string);

#endif
