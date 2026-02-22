#ifndef CONFIG_TEMPLATE_HPP
#define CONFIG_TEMPLATE_HPP

#include <string>
#include <string_view>

class ConfigCompile {
  public:
    void create();
    std::string get_compile_command(std::string_view programming_language);
};

#endif
