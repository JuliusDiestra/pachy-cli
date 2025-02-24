/**
 * @file cli_flag.hpp
 *
 */

#ifndef ARG_PARSER_CLI_FLAG_HPP_
#define ARG_PARSER_CLI_FLAG_HPP_

namespace pachy {
/**
 * @class CliFlag
 * @brief Class to stored cli flag and its args.
 *
 */

class CliFlag {
  public:
    CliFlag() : flag_{}, args_{}{};
    CliFlag(std::string flag) : flag_{flag}, args_{}{};
    CliFlag(std::string flag, std::vector<std::string> args) : flag_{flag}, args_{args}{};
    void set_flag(std::string flag) {
        flag_ = flag;
    };
    void set_args(std::vector<std::string> args) {
        args_ = args;
    };
    void add_arg(std::string arg) {
        args_.push_back(arg);
    }
    const std::string& get_flag() const {
        return flag_;
    }
    const std::vector<std::string>& get_args() const {
        return args_;
    }
  private:
    std::string flag_;
    std::vector<std::string> args_;
};
}  // pachy

#endif  // ARG_PARSER_CLI_FLAG_HPP_
