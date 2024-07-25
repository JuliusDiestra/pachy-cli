
#include "status_code.hpp"

namespace pachy {

StatusCode::StatusCode() :
  status_type_{StatusType::kSuccess} {}

StatusCode::StatusCode(StatusType status_type) :
  status_type_{status_type} {}

void StatusCode::set_status_type(StatusType status_type) {
    status_type_ = status_type;
}

StatusType StatusCode::status_type() const {
    return status_type_;
}

bool StatusCode::success() const {
    bool bool_;
    if (status_type_ == StatusType::kSuccess) {
        bool_ = true;
    } else {
        bool_ = false;
    }
    return bool_;
}

bool StatusCode::failure() const {
    return !success();
}

const std::string StatusCode::error_message() const {
    switch (status_type_) {
        case pachy::StatusType::kSuccess :
            return std::string{"No error detected."};
            break;
        default:
            return std::string{"Unknown error."};
            break;
    }
}

}  // namespace pachy
