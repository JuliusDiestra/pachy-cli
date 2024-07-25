
#include "exception.hpp"

namespace pachy {

Exception::Exception(const StatusCode& status_code) :
  std::runtime_error(status_code.error_message()),
  status_code_{status_code} {
    if (status_code_.success()) {
        throw std::invalid_argument(
            "pachy::Exception constructor argument should be an StatusCode "
            "class storing a failure.");
    }
}

StatusCode Exception::status_code() const {
    return status_code_;
}

}  // namespace pachy
