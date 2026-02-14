#include "structs/metadata.hpp"
#include "enums/exit_code.hpp"
#include "utils.hpp"
#include "version.hpp"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

void Metadata::create_metadata_file(void) {
	std::ofstream metadata_file(METADATA_FILE_NAME);
	if (!metadata_file.is_open()) {
		throw ExitCodeException(ExitCode::INTERNAL_PROGRAM_ERROR,
		                        "Failed to create metadata file");
	}

	std::string current_time_and_date = utils::get_time_and_date();

	metadata_file << "// tgpc's metadata file: DO NOT DELETE!\n"
	              << ProgrammingLanguage << "\n"
	              << current_time_and_date << PROGRAM_VERSION << "\n";
}

std::string Metadata::get(Key key) {
	std::size_t current_line =
	    0; // Skip the first line as it doesn't contain useful info
	std::size_t requested_line = std::to_underlying(key);

	// the second line contains the programming language, third creation date,
	// fourth used program version

	std::ifstream file(METADATA_FILE_NAME);
	if (!file.is_open()) {
		throw ExitCodeException(ExitCode::METADATA_NOT_FOUND,
		                        "Metadata file not found");
	}

	std::string line;
	while (std::getline(file, line)) {
        ++current_line;

		if (current_line == requested_line) {
			return line;
		}
	}

	throw ExitCodeException(ExitCode::INTERNAL_PROGRAM_ERROR,
	                        "Out of metadata lines, should'nt happen!");
}
