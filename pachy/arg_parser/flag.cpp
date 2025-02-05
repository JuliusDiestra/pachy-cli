

#include "flag.hpp"

#include "pachy/error_handling/exception.hpp"
#include "pachy/error_handling/status_type.hpp"

namespace pachy {

Flag::Flag(std::string short_flag, std::string long_flag, std::string description_flag, bool is_boolean, std::size_t max_args) :
    short_{short_flag},
    long_{long_flag},
    description_{description_flag},
    is_used_{false},
    is_boolean_{is_boolean},
    args_{},
    max_args_{max_args}{}

Flag::Flag(std::string short_flag, std::string long_flag, std::string description_flag) :
    Flag(short_flag, long_flag, description_flag, true, 0) {};

void Flag::set_used() {
    is_used_ = true;
}

bool Flag::is_used() const {
    return is_used_;
}

const std::string& Flag::get_short() const {
    return short_;
}

const std::string& Flag::get_long() const {
    return long_;
}

const std::string& Flag::get_description() const {
    return description_;
}

StatusCode Flag::append_arg(std::string flag_arg) {
    if (is_boolean_) {
        // Return error because arguments are not allowed
        return pachy::StatusCode{pachy::StatusType::kArgumentNotSupported};
    }
    if (max_args_ > 0) {
        if (args_.size() < max_args_ ) {
            args_.push_back(flag_arg);
            return pachy::StatusCode{pachy::StatusType::kSuccess};
        } else {
            // Return error due to passing max number of arguments
            return pachy::StatusCode{pachy::StatusType::kArgumentMaxNumber};
        }
    } else {
        return pachy::StatusCode{pachy::StatusType::kArgumentNotSupported};
    }
}

const std::vector<std::string>& Flag::get_args() const {
    return args_;
}

}  // namespace pachy
