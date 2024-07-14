#ifndef RUNNER_RUNNER_HPP_
#define RUNNER_RUNNER_HPP_

#include <vector>
#include <string>

namespace pachy {

class Runner {
  public:
    Runner();
    int Execute(const std::vector<std::string>& args);
  private:
};

}  // namespace pachy

#endif  // ARG_PARSER_PARSER_HPP_
