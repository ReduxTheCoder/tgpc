#include "enums/exit_code.hpp"
#include <enums/command.hpp>
#include <iostream>

int main(int argc, const char **argv) {
	TgpcCommand command;
	try {
		command = get_enum_command_from_string(argc, argv);
	} catch (const ExitCodeException &e) {
		std::cout << "Incorrect program usage...\n";
        return static_cast<int>(e.code);
	}

	switch (command) {
	case TgpcCommand::NEW:
		break;
	default:
		break;
	}
}
