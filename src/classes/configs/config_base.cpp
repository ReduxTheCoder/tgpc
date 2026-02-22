#include <classes/configs/config_base.hpp>
#include <filesystem>

void Config::create() {
    std::filesystem::create_directories(".tgpc");
}
