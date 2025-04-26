
#include "yaml_parser.hpp"

namespace pachy {

YamlParser::YamlParser() :
    file_system_handler_{},
    file_handler_{},
    file_parser_{},
    data_{}{}

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
        // open yaml file
        auto status_open_file = file_handler_.open(files_in_pachy_dir.at(j));
        if (status_open_file.failure()) {
            // error opening file
            return StatusCode{StatusType::kUnknownError};
        }
        auto file_parsed_sr = file_parser_.parse(file_handler_.get_file());
        if (!file_parsed_sr.has_value()) {
            // error while error parsing yaml file.
            return file_parsed_sr.status_code();
        }
        const auto add_data_status = data_.add(std::move(file_parsed_sr.value()));
        if (add_data_status.failure()) {
            return add_data_status;
        }
    }
    return StatusCode();
}

}  // namespace pachy
