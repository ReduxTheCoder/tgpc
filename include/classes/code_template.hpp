#ifndef USER_TEMPLATE_HPP
#define USER_TEMPLATE_HPP

#include "classes/template_base.hpp"
#include "enums/programming_language.hpp"

class CodeTemplate : public TemplateBase {
    public:
	CodeTemplate(ProgrammingLanguage programming_language)
	    : TemplateBase(programming_language) {
            populate_template();
        }

    void populate_template() override;
};

#endif
