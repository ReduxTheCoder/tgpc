#include "enums/command.hpp"
#include "enums/exit_code.hpp"
#include "other.hpp"
#include "structs/project_config.hpp"
#include <iostream>

int main(int argc, const char **argv) {
	TgpcCommand command;
	try {
		command = get_enum_command_from_string(argc, argv);
	} catch (const ExitCodeException &e) {
		std::cerr << "Incorrect program usage...\n";
		return static_cast<int>(e.code);
	}

	switch (command) {
	case TgpcCommand::NEW: {
		bool error = false;
		if (argc < 3) {
			error = true;
			std::cerr << "Project name wasn't given\n";
		}
		if (argc < 4) {
			error = true;
			std::cerr << "Project programming language wasn't given\n";
		}

		if (error) {
			return static_cast<int>(ExitCode::INCORRECT_PROGRAM_USAGE);
		}

		ProjectConfig project_config(argv[2], argv[3]);

		try {
			project_config.create_project();
		} catch (const ExitCodeException &e) {
			std::cerr << "[Error] (Error code "
			          << static_cast<int>(e.code) << ") " << e.what() << "\n";
			return static_cast<int>(e.code);
		}
		break;
    }
    case TgpcCommand::HELP: {
        other::display_help();
        break;
    }
	default:
		break;
	}
}
