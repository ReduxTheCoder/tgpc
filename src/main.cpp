#include "enums/command.hpp"
#include "enums/exit_code.hpp"
#include "other.hpp"
#include "classes/project_config.hpp"
#include <iostream>
#include <utility>

using std::to_underlying;

int main(int argc, const char **argv) {
	TgpcCommand command;
	try {
		command = get_enum_command_from_string(argc, argv);
	} catch (const ExitCodeException &e) {
		std::cerr << "Incorrect program usage...\n";
		return to_underlying(e.code);
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
			return to_underlying(ExitCode::INCORRECT_PROGRAM_USAGE);
		}

		ProjectConfig project_config(argv[2], argv[3]);

		try {
			project_config.create_project();
		} catch (const ExitCodeException &e) {
			std::cerr << "[Error] (Error code "
			          << to_underlying(e.code) << ") " << e.what() << "\n";
			return to_underlying(e.code);
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
