#ifndef MAIN_PACHY_HPP_
#define MAIN_PACHY_HPP_

#include <vector>
#include <string>

#include "pachy/arg_parser/arg_parser.hpp"
#include "pachy/error_handling/status_code.hpp"
#include "printer.hpp"

namespace pachy {

class Pachy {
  public:
    Pachy() = delete;
    Pachy(const std::vector<std::string>& input_cli_args);
    int execute();
  private:
    pachy::ArgParser arg_parser_;
    pachy::Printer printer_;
    const std::vector<std::string>& input_cli_args_;
    pachy::StatusCode add_flags();
};

}  // namespace pachy

#endif  // MAIN_PACHY_HPP_
