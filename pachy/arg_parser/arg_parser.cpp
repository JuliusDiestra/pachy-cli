
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
    // Pre-Verification of cli_args and store in cli_flag_contailer_
    //  1. Arguments without flag are not allowed.
    //      For Example:
    //          pachy d -v 23
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
    // Update values in flag_contailer_ from cli_flag_container_
    for (std::size_t j{}; j < cli_flag_container_.size(); ++j) {
        auto status_flag_index = get_flag_index(cli_flag_container_.at(j).get_flag());
        if (status_flag_index.has_value()) {
            auto index = status_flag_index.value();
            // Set flag as used.
            flag_container_.at(index).set_used();
            // Append args if applied
            if (cli_flag_container_.at(j).size_args() > 0) {
                // Apend args.
                auto status_append = flag_container_.at(index).set_args(cli_flag_container_.at(j).get_args());
                if (status_append.failure()) {
                    return status_append;
                }
            } else {
                if (!flag_container_.at(index).is_boolean()) {
                    // Error. Flag needs arguments.
                    return StatusCode{StatusType::kUnknownError};
                }
            }
        } else {
            // Error : Flag in cli_flag_container_ was not found in flag_container_.
            return StatusCode{StatusType::kUnknownError};
        }
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

}  // namespace pachy
