#ifndef MAIN_PACHY_HPP_
#define MAIN_PACHY_HPP_

#include <memory>

#include "pachy/arg_parser/parser.hpp"
#include "pachy/runner/runner.hpp"

namespace pachy {

class Pachy {
  public:
    Pachy() = delete;
    Pachy(const int& argc, char* argv[]);
    int Execute();
  private:
    pachy::ArgParser arg_parser_;
    std::unique_ptr<pachy::Runner> runner_;
};

}  // namespace pachy

#endif  // MAIN_PACHY_HPP_
