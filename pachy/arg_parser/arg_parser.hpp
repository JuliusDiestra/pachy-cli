/**
 * @file arg_parser.hpp
 *
 */

#ifndef ARG_PARSER_PARSER_HPP_
#define ARG_PARSER_PARSER_HPP_

#include <vector>
#include <string>

#include "pachy/error_handling/status_code.hpp"
#include "pachy/error_handling/status_return.hpp"
#include "flag.hpp"
#include "cli_flag.hpp"

namespace pachy {

/**
 * @class ArgParser
 * @brief Main class to parse command line arguments. Use this class to add
 * flags and access information from each flag.
 *
 */
class ArgParser {
  public:
    /**
     * @brief Default constructor.
     *
     * Creates an ArgParser instance without arguments stored.
     *
     */
    ArgParser();
    /**
     * @brief Method to store add/store a Flag instance.
     *
     * @param flag Flag instance.
     *
     */
    pachy::StatusCode add_flag(pachy::Flag flag);

    /**
     * @brief Method to get number of Flags added.
     *
     */
    std::size_t size() const;

    /**
     * @brief Method to parse arguments for each flag stored.
     *
     * Command line interface input arguments are use to update each Flag
     * instance information.
     *
     * @param input_cli_args Command line interface input arguments.
     *
     */
    pachy::StatusCode parse(const std::vector<std::string>& input_cli_args);

    /**
     * @brief Method to check if Flag string short or long is used.
     *
     * @param flag_string Short or long flag string.
     *
     */
    bool is_flag_used(const std::string& flag_string) const;
  private:
    StatusReturn<std::size_t> get_flag_index(const std::string& flag_string) const;
    bool is_repeated_flag(const Flag& flag) const;
    bool is_flag(const std::string& flag) const;
    std::vector<Flag> flag_container_;
    std::vector<CliFlag> cli_flag_container_;
};

}  // namespace pachy

#endif  // ARG_PARSER_PARSER_HPP_
