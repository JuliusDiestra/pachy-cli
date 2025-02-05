
#include "arg_parser.hpp"
#include <iostream>

namespace pachy {

ArgParser::ArgParser() {}

pachy::StatusCode ArgParser::add_flag(pachy::Flag flag) {
    if (!is_repeated_flag(flag)) {
        flag_container_.push_back(flag);
        return StatusCode();
    } else {
        return StatusCode(StatusType::kRepeatedFlag);
    }
}

std::size_t ArgParser::size() const {
    return flag_container_.size();
}

pachy::StatusCode ArgParser::parse(const std::vector<std::string>& input_cli_args) {
    auto status_code_verification = verification_cli_args(input_cli_args);
    if (status_code_verification.failure()) {
        return status_code_verification;
    }
    for (std::size_t j{0}; j < input_cli_args.size(); ++j) {
        std::cout << "j : " << input_cli_args.at(j) << std::endl;
    }
    return pachy::StatusCode();
}

bool ArgParser::is_flag_used(const std::string& flag_string) const {
    auto index_status = get_flag_index(flag_string);
    bool result;
    if (index_status.has_value()) {
        result = flag_container_.at(index_status.value()).is_used();
    } else {
        result = false;
    }
    return result;
}

StatusReturn<std::size_t> ArgParser::get_flag_index(const std::string& flag_string) const {
    for (std::size_t j = 0; j < flag_container_.size(); ++j) {
        bool is_flag_found = (flag_container_.at(j).get_short().compare(flag_string) == 0) || (flag_container_.at(j).get_long().compare(flag_string) == 0);
        if (is_flag_found) {
            return StatusReturn<std::size_t>{j};
        }
    }
    // In case flag_string is not found inside the flag_container_
    return StatusReturn<std::size_t>{StatusCode{StatusType::kFlagDoesNotExist}};
}

bool ArgParser::is_repeated_flag(const Flag& flag) const {
    if (!(get_flag_index(flag.get_short()).has_value()) && !(get_flag_index(flag.get_long()).has_value())) {
        return false;
    } else {
        return true;
    }
}

StatusCode ArgParser::verification_cli_args(const std::vector<std::string>& input_cli_args) const {
    return StatusCode();
}

}  // namespace pachy
