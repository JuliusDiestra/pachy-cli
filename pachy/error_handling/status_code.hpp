/**
 * @file status_code.hpp
 *
 */

#ifndef PACHY_ERROR_HANDLING_STATUS_CODE_HPP_
#define PACHY_ERROR_HANDLING_STATUS_CODE_HPP_


#include <string>

#include "status_type.hpp"

namespace pachy {

/**
 * @class StatusCode
 * @brief Status code class. This class contains information of operations
 * status. While error, this class should be used to throw exceptions.
 */

class StatusCode {
  public:
    StatusCode();
    StatusCode(StatusType status_type);
    void set_status_type(StatusType status_type);
    StatusType status_type() const;
    bool success() const;
    bool failure() const;
    const std::string error_message() const;

  private:
    StatusType status_type_;
};

}  // namespace pachy

#endif  // PACHY_ERROR_HANDLING_STATUS_CODE_HPP_
