#ifndef ARG_PARSER_PARSER_HPP_
#define ARG_PARSER_PARSER_HPP_

#include <vector>
#include <string>

#include "logger.hpp"

namespace pachy {

class ArgParser {
  public:
    ArgParser() = delete;
    explicit ArgParser(const int& argc, char* argv[]);
    void Validate();
    bool IsHelp() const;
    bool IsVersion() const;
    const std::vector<std::string>& GetArguments() const;
  private:
    std::vector<std::string> args_;
    pachy::Logger logger_;
};

}  // namespace pachy

#endif  // ARG_PARSER_PARSER_HPP_
