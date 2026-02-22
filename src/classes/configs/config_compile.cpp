#include "enums/exit_code.hpp"
#include <classes/configs/config_compile.hpp>
#include <cstddef>
#include <fstream>

void ConfigCompile::create() {
    // Create the compile_commands.tgpc file, the std::ios::app at the end is so that
    // the file isnt truncated if it exists, but i just realized how stupid that is.
    // i mean, the program can't even run if there's another project with its same name,
    // but im just too lazy to press `:10, $, h, v, b x6, l, d`, too bad.
    // and now that i think about it, im making a comment so long and wasting my time,
    // i love programming this program, i really do, i could shower, but, instead, im
    // programming and getting continous headaches. Just because i love my computer.
    // p.s.: i hope NO ONE reads this       - San_Genna (who else but me?), 16/02/26
    std::ofstream file("compile_commands.tgpc", std::ios::app);
    if (!file.is_open()) {
        throw ExitCodeException(
            ExitCode::INTERNAL_PROGRAM_ERROR,
            "Failed to create compile_commands.tgpc file");
    }
}

static std::string_view trim(std::string_view s) {
    size_t start = s.find_first_not_of(" \t\r");
    if (start == std::string_view::npos) return {};

    size_t end = s.find_last_not_of(" \t\r");
    return s.substr(start, end - start + 1);
}

std::string ConfigCompile::get_compile_command(std::string_view programming_language) {
    std::ifstream file(".tgpc/compile_commands.tgpc");
    if (!file.is_open()) {
        throw ExitCodeException(
            ExitCode::INCORRECT_PROGRAM_USAGE,
            "Failed to open compile_commands.tgpc file");
    }

    std::string line;

    while (std::getline(file, line)) {
        std::string_view view(line);

        auto colon = view.find(':');
        if (colon == std::string_view::npos) continue;

        auto key = trim(view.substr(0, colon));
        if (key != programming_language) continue;

        auto value = trim(view.substr(colon + 1));
        return std::string(value);
    }

    return "";
}




















