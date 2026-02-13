#include "utils.hpp"
#include <ctime>
#include <chrono>
#include <string>

namespace utils {
std::string get_time_and_date(void) {
    auto current = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(current);
    std::string current_time_str = std::ctime(&current_time);
    return current_time_str;
}
}
