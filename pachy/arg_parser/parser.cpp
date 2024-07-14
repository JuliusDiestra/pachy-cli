
#include "parser.hpp"

namespace pachy {

ArgParser::ArgParser(const int& argc, char* argv[]) {
    for (auto j = 1; j < argc; ++j) {
        args_.push_back(argv[j]);
    }
}

void ArgParser::Validate() {
}

bool ArgParser::IsHelp() const {
    bool is_help{false};
    if (args_.size() == 1) {
        auto& arg = args_.at(0);
        if (arg == "-h" || arg == "--h" || arg == "--help") {
            is_help = true;
            logger_.PrintHelp();
        }
    }
    return is_help;
}

bool ArgParser::IsVersion() const {
    bool is_version{false};
    if (args_.size() == 1) {
        auto& arg = args_.at(0);
        if (arg == "-v" || arg == "--v" || arg == "--version") {
            is_version = true;
            logger_.PrintVersion();
        }
    }
    return is_version;
}
const std::vector<std::string>& ArgParser::GetArguments() const {
    return args_;
}
}  // namespace pachy
