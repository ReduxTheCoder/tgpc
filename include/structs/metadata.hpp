#ifndef METADATA_HPP
#define METADATA_HPP

#include <string>

#define METADATA_FILE_NAME ".tgpc_meta"

struct Metadata {
    enum class Key {
        PROGRAMMING_LANGUAGE = 2,
        CREATION_DATE = 3,
        USED_PROGRAM_VERSION = 4,
    };

    std::string ProgrammingLanguage;

    explicit Metadata(std::string language)
        : ProgrammingLanguage(std::move(language)) {}

    void create_metadata_file(void);
    static std::string get(Key key);
};

#endif
