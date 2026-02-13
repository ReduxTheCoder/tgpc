#ifndef COMMAND_HPP
#define COMMAND_HPP

enum class TgpcCommand {
	NEW,
	/*COMMAND_HELP,
	COMMAND_RUN,
	COMMAND_CONFIG,
	COMMAND_DATA,
	COMMAND_UPDATE, */
	UNKNOWN,
};

TgpcCommand get_enum_command_from_string(int argc, const char **argv);

#endif
