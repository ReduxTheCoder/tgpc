#ifndef COMPILE_TEMPLATE_HPP
#define COMPILE_TEMPLATE_HPP

#include "classes/template_base.hpp"
#include "enums/programming_language.hpp"
#include <vector>

class CompileTemplate : public TemplateBase {
  private:
    std::vector<std::string> TemplateArgs;

  public:
    CompileTemplate(ProgrammingLanguage programming_language)
        : TemplateBase(programming_language) {
        populate_template();
    }

    void populate_template() override;
};

#endif
