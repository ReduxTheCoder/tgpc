#include "other.hpp"
#include <iostream>

namespace other {
void display_help(void) {
    std::cout << "Usage: tgpc [COMMAND] [OPTIONS]\n\n";
    std::cout << "A C++ program to manage projects.\n";

    std::cout << "Commands:\n";
    std::cout << "  new [PROJECT_NAME] [PROJECT_PROGRAMMING_LANG]       Create a new project\n";
    std::cout << "  help                                                Display this help message\n";
}
}
