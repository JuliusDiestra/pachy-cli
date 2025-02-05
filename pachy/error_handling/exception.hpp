/**
 * @file exception.hpp
 *
 */

#ifndef PACHY_ERROR_HANDLING_EXCEPTION_HPP_
#define PACHY_ERROR_HANDLING_EXCEPTION_HPP_

#include <stdexcept>
#include <string>

#include "status_code.hpp"

namespace pachy {

class Exception : public std::runtime_error {
  public:
    Exception() = delete;
    explicit Exception(const StatusCode& status_code);
    StatusCode status_code() const;

  private:
    StatusCode status_code_;
};

}  // namespace pachy

#endif  // PACHY_ERROR_HANDLING_EXCEPTION_HPP_
