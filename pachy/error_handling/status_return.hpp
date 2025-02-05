/**
 * @file status_return.hpp
 *
 */

#ifndef PACHY_ERROR_HANDLING_STATUS_RETURN_HPP_
#define PACHY_ERROR_HANDLING_STATUS_RETURN_HPP_

#include <optional>

#include "status_code.hpp"
#include "exception.hpp"

namespace pachy {

/**
 * @class StatusReturn
 * @brief Status return class. This class contains a return value of a function
 * and also status code in case there is an error while the function was called.
 * This class is supposed to be used instead of std::expected (since c++23).
 */

template<typename T>
class StatusReturn {
  public:
    StatusReturn() = delete;
    StatusReturn(T value) : status_code_{}, has_value_{true} {
        value_.emplace(value);
    };
    StatusReturn(StatusCode status_code) : has_value_{false} {
        if (status_code.success()) {
            // Throw error : While we create with StatusCode, only error is accepted.
            throw pachy::Exception(pachy::StatusCode(pachy::StatusType::kStatusReturnConstructor));
        }
        status_code_ = status_code;
    };
    const T& value() const {
        if (!has_value_) {
            // Throw error if value object is accessed.
            throw pachy::Exception(pachy::StatusCode(pachy::StatusType::kStatusReturnNoValue));
        }
        return value_.value();
    };
    const StatusCode& status_code() const {
        return status_code_;
    };
    bool has_value() const {
        return has_value_;
    }
  private:
    std::optional<T> value_;
    StatusCode status_code_;
    bool has_value_;
};

}  // namespace pachy

#endif  // PACHY_ERROR_HANDLING_STATUS_CODE_HPP_
