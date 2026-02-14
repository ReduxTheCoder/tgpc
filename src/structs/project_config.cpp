#include "classes/project_config.hpp"
#include "structs/metadata.hpp"
#include "command_executor.hpp"
#include "enums/exit_code.hpp"
#include "enums/programming_language.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

void ProjectConfig::create_project(void) {
	ProgrammingLanguage programming_language_enum =
	    get_enum_programming_language_from_string(&ProgrammingLanguageString);

	namespace fs = std::filesystem;
	if (fs::exists(ProjectName)) {
		std::string item_type, command;

		if (fs::is_directory(ProjectName)) {
			item_type = "directory";
			command = "rm -r";
		} else {
			item_type = "file";
			command = "rm";
		}

		std::string error =
		    item_type +
		    " named like the project already exists.\nTry running `" + command +
		    " " + ProjectName + "`\n";
		throw ExitCodeException(ExitCode::ITEM_EXISTS, error);
	}

	bool create_main_file = false;

	switch (programming_language_enum) {
	case ProgrammingLanguage::RUST:
		execute_command("cargo", {"new", ProjectName});
		break;
	case ProgrammingLanguage::GO:
		execute_command("go", {"mod", "init", ProjectName});
		break;
	default:
		std::filesystem::create_directories(ProjectName);
		create_main_file = true;
		break;
	}

	std::filesystem::current_path(ProjectName);

    Metadata metadata(ProgrammingLanguageString);

	try {
        metadata.create_metadata_file();
	} catch (const ExitCodeException &e) {
        std::cerr << "[Error] (Error code "
                  << static_cast<int>(e.code) << ") " << e.what() << "\n";
		throw;
	}

	if (create_main_file) {
		std::string main_file_name = "main." + ProgrammingLanguageString;
		std::ofstream main_file(main_file_name);
		if (!main_file.is_open()) {
			throw ExitCodeException(ExitCode::INTERNAL_PROGRAM_ERROR,
			                        "Failed to create main file.");
		}

		main_file << "Templates not implemented...\n";
	}
}
