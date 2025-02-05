#ifndef PACHY_ARG_PARSER_FLAG_HPP_
#define PACHY_ARG_PARSER_FLAG_HPP_

#include <string>
#include <vector>

#include "pachy/error_handling/status_code.hpp"

namespace pachy {

class Flag {
  public:
    explicit Flag(std::string short_flag, std::string long_flag, std::string description_flag, bool is_boolean, std::size_t max_args);
    explicit Flag(std::string short_flag, std::string long_flag, std::string description_flag);
    void set_used();
    bool is_used() const;
    const std::string& get_short() const;
    const std::string& get_long() const;
    const std::string& get_description() const;
    StatusCode append_arg(std::string flag_arg);
    const std::vector<std::string>& get_args() const;
  private:
    std::string short_;
    std::string long_;
    std::string description_;
    bool is_used_;
    bool is_boolean_;
    std::vector<std::string> args_;
    std::size_t max_args_;
};


}  //  namespace pachy

#endif  // PACHY_ARG_PARSER_FLAG_HPP_
