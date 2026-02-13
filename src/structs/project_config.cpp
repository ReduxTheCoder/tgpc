#include "structs/project_config.hpp"
#include "command_executor.hpp"
#include "enums/exit_code.hpp"
#include "enums/programming_language.hpp"
#include "utils.hpp"
#include "version.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

void ProjectConfig::create_metadata_file(void) {
	std::ofstream metadata_file(".tgpc_meta");
	if (!metadata_file.is_open()) {
		throw ExitCodeException(ExitCode::INTERNAL_PROGRAM_ERROR,
		                        "Failed to create metadata file");
	}

	std::string current_time_and_date = utils::get_time_and_date();

	metadata_file << ProgrammingLanguageString << "\n"
	              << current_time_and_date
	              << PROGRAM_VERSION << "\n";

	metadata_file.close();
}

void ProjectConfig::create_project(void) {
	ProgrammingLanguage programming_language_enum =
	    get_enum_programming_language_from_string(&ProgrammingLanguageString);

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

	try {
		this->create_metadata_file();
	} catch (const ExitCodeException &e) {
		std::cerr << "Unexpected exception occurred: (error code: "
		            << static_cast<int>(e.code)
                    << "): " << e.what() << "\n";
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
