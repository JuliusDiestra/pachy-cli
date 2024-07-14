#ifndef ARG_PARSER_LOGGER_HPP_
#define ARG_PARSER_LOGGER_HPP_

namespace pachy {

class Logger {
  public:
    Logger() = default;
    void PrintHelp() const;
    void PrintVersion() const;
};

}  // namespace pachy

#endif  // ARG_PARSER_LOGGER_HPP_
