#include "enums/command.hpp"
#include "enums/exit_code.hpp"
#include <string>

TgpcCommand get_enum_command_from_string(int argc, const char **argv) {
	if (argc < 2) {
		throw ExitCodeException(ExitCode::INCORRECT_PROGRAM_USAGE);
	}

	std::string command = argv[1];

    if (command == "new") return TgpcCommand::NEW;
    if (command == "help") return TgpcCommand::HELP;
    if (command == "compile") return TgpcCommand::COMPILE;
    else throw ExitCodeException(ExitCode::UNKNOWN_COMMAND);
}
