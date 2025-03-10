
#include "yaml_parser.hpp"

#include <filesystem>
#include <iostream>

namespace pachy {

YamlParser::YamlParser() {}

StatusCode YamlParser::parse() {
    // Get all files inside .pachy directory
    if (!file_system_handler_.pachy_dir_exists()) {
        // Return error that .pachy dir doesn't exists
        return StatusCode{StatusType::kUnknownError};
    }
    auto files_in_pachy_dir = file_system_handler_.get_file_paths();
    if (files_in_pachy_dir.empty()) {
        // Return error that .pachy dir does not have yaml files.
        return StatusCode{StatusType::kUnknownError};
    }
    for (std::size_t j{0}; j < files_in_pachy_dir.size(); ++j) {
        // read yaml file and gets jobs.
    }
    return StatusCode();
}

}  // namespace pachy
