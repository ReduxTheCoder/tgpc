#ifndef COMPILE_TEMPLATE_HPP
#define COMPILE_TEMPLATE_HPP

#include "classes/templates/template_base.hpp"
#include "enums/programming_language.hpp"
#include <string>
#include <vector>

class CompileTemplate : public TemplateBase {
  private:
    std::vector<std::string> TemplateArgs;

  public:
    CompileTemplate(ProgrammingLanguage programming_language)
        : TemplateBase(programming_language) {
        populate_template();
    }

    const std::vector<std::string>& get_template_argument() const { return TemplateArgs; };
    void populate_template() override;
};

#endif
