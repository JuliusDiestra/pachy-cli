
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
    // Verification cli_args
    //  1. Arguments without flag is an error: pachy d -v 23
    bool is_flag_registered = false;
    for (std::size_t j{0}; j < input_cli_args.size(); ++j) {
        if (is_flag(input_cli_args.at(j))) {
            is_flag_registered = true;
            // Use string to get the index of the corresponding registered Flag.
            auto status_cli = get_flag_index(input_cli_args.at(j));
            if (status_cli.has_value()) {
                cli_flag_container_.push_back(CliFlag(input_cli_args.at(j)));
            } else {
                // Error : Unknown flag from input_cli_args
                return StatusCode{StatusType::kUnknownError};
            }
        } else {
            if (!is_flag_registered) {
                // Error : arguments should be afte a flag.
                return StatusCode{StatusType::kUnknownError};
            }
            cli_flag_container_.back().add_arg(input_cli_args.at(j));
        }
    }
    // Update information in flag_container_ from cli_flag_container_ information.
    auto status_code_verification = verification_cli_args(input_cli_args);
    if (status_code_verification.failure()) {
        return status_code_verification;
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

bool ArgParser::is_flag(const std::string& flag) const {
    return (flag.compare(0,1,"-") == 0);
}

StatusCode ArgParser::verification_cli_args(const std::vector<std::string>& input_cli_args) const {
    // Grab flags : if has "-" or "--"
    std::vector<std::string> cli_flags;
    for (std::size_t j{0}; j < input_cli_args.size()  ;++j) {
        if ((input_cli_args.at(j).substr(0,1) == "-") || (input_cli_args.at(j).substr(0,2) == "--")) {
            cli_flags.push_back(input_cli_args.at(j));
        }
    }
    // Check if flags are registered flags.
    return StatusCode();
}

}  // namespace pachy
