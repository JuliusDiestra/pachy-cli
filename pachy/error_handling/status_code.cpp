
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
    return (status_type_ == StatusType::kSuccess);
}

bool StatusCode::failure() const {
    return !success();
}

const std::string StatusCode::error_message() const {
    switch (status_type_) {
        case pachy::StatusType::kSuccess :
            return std::string{"No error detected."};
            break;
        case pachy::StatusType::kStatusReturnConstructor :
            return std::string{"StatusReturn constructor only accepts StatusCode for Error."};
            break;
        case pachy::StatusType::kStatusReturnNoValue :
            return std::string{"StatusReturn does not contain value."};
            break;
        case pachy::StatusType::kArgumentNotSupported :
            return std::string{"Arguments are not supported for this flag."};
            break;
        case pachy::StatusType::kArgumentMaxNumber :
            return std::string{"Maximum number of arguments are exceeded."};
            break;
        case pachy::StatusType::kRepeatedFlag :
            return std::string{"Flag added is reaped. This means the flag was already added."};
            break;
        case pachy::StatusType::kFlagDoesNotExist :
            return std::string{"Flag does not exists inside Arguments class."};
            break;
        default:
            return std::string{"Unknown error."};
            break;
    }
}

}  // namespace pachy
