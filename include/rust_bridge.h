# pragma once
# include "enums.h"
# include "utils.h"

ProgrammingLanguage get_language_enum_from_str_rust(const char * lang);
ConfigFile get_enum_config_from_str_rust(const char * config);
ConfigCmd get_enum_config_cmd_from_str_rust(const char * cmd);
TgpcCommand get_tgpc_command_from_str_rust(const char * cmd);
