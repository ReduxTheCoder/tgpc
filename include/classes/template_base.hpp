#ifndef TEMPLATE_BASE_HPP
#define TEMPLATE_BASE_HPP

#include "enums/programming_language.hpp"
class TemplateBase {
    protected:
        ProgrammingLanguage ProgrammingLang;
        std::string Template;

        TemplateBase(ProgrammingLanguage programming_language) : ProgrammingLang(programming_language) {}

    public:
        virtual ~TemplateBase() = default;

        const std::string& get_template() const { return Template; }

        virtual void populate_template() = 0;
};

#endif
