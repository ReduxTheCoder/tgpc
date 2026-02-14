// #include "classes/compile_template.hpp"
// #include "command_executor.hpp"
// #include "commands/compile.hpp"
// #include "enums/programming_language.hpp"
// #include "structs/metadata.hpp"
// #include <iostream>
//
// void compile_project(void) {
// 	std::string programming_language =
// 	    Metadata::get(Metadata::Key::PROGRAMMING_LANGUAGE);
//
// 	ProgrammingLanguage programming_language_enum =
// 	    get_enum_programming_language_from_string(&programming_language);
//
//     CompileTemplate compile_template(programming_language_enum);
//     
//     execute_command(compile_template.get_template(), compile_template.get_template_argument());
//     std::cout << "\rExecuting compile command...";
//     std::cout << "Compiled!";
// }

#include "classes/compile_template.hpp"
#include "command_executor.hpp"
#include "commands/compile.hpp"
#include "enums/programming_language.hpp"
#include "structs/metadata.hpp"
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

void compile_project() {
    std::string programming_language =
        Metadata::get(Metadata::Key::PROGRAMMING_LANGUAGE);

    ProgrammingLanguage programming_language_enum =
        get_enum_programming_language_from_string(&programming_language);

    CompileTemplate compile_template(programming_language_enum);
    
    std::atomic<bool> done(false);

    // Start execute_command in a separate thread
    std::thread worker([&]() {
        execute_command(compile_template.get_template(),
                        compile_template.get_template_argument());
        done = true;
    });

    // Spinner characters
    const char spinner[] = {'/', '-', '\\', '|'};
    int spinner_index = 0;

    // Display spinner while execute_command is running
    while (!done) {
        std::cout << "\rExecuting compile command... " << spinner[spinner_index] << std::flush;
        spinner_index = (spinner_index + 1) % 4;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    worker.join();

    std::cout << "\rExecuting compile command... Done!   " << std::endl;
}
