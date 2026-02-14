#ifndef PROJECT_CONFIG_HPP
#define PROJECT_CONFIG_HPP

#include <string>

class ProjectConfig {
    std::string ProjectName;
    std::string ProgrammingLanguageString;
    
    public:
    ProjectConfig(const std::string& name, const std::string& language)
        : ProjectName(name), ProgrammingLanguageString(language) {}
    void create_project(void);
};

#endif
