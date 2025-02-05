
#include "pachy.hpp"

#include <iostream>

namespace pachy {

Pachy::Pachy(const std::vector<std::string>& input_cli_args) : input_cli_args_{input_cli_args} {
}

int Pachy::execute() {
    int error_code_success{0};
    int error_code_failure{1};
    auto status_add_flags = add_flags();
    if (status_add_flags.failure()) {
        std::cerr << status_add_flags.error_message() << std::endl;
        return error_code_failure;
    }
    auto status_parse = arg_parser_.parse(input_cli_args_);
    if (status_parse.failure()) {
        std::cerr << status_parse.error_message() << std::endl;
        return error_code_failure;
    }
    if (is_help()) {
        printer_.help();
    }
    if (is_version()) {
        printer_.version();
    }
    std::cout << "Pachy run" << std::endl;
    std::cout << "Flags : " << arg_parser_.size() << std::endl;
    return error_code_success;
}

StatusCode Pachy::add_flags() {
    StatusCode status{};
    // Version
    pachy::Flag version_flag{"-v","--v","Display version."};
    status = arg_parser_.add_flag(version_flag);
    if (status.failure()) {
        return status;
    }
    // Help
    pachy::Flag help_flag{"-h","--h","Display help menu."};
    status = arg_parser_.add_flag(help_flag);
    if (status.failure()) {
        return status;
    }
    // Run
    pachy::Flag run_flag{"-r","--r","Run jobs or single pipeline."};
    status = arg_parser_.add_flag(run_flag);
    if (status.failure()) {
        return status;
    }
    return status;
}

bool Pachy::is_help() const {
    return arg_parser_.is_flag_used("-h");
}

bool Pachy::is_version() const {
    return arg_parser_.is_flag_used("-v");
}

}  // namespace pachy

