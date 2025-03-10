
#include "pachy.hpp"

#include <iostream>

namespace {
const pachy::Flag kVersionFlag{"-v","--version","Display version."};
const pachy::Flag kHelpFlag{"-h","--help","Display help menu."};
const pachy::Flag kJobFlag{"-j","--job","Run specified job."};
const pachy::Flag kPipelineFlag{"-p","--pipeline","Run specified pipeline."};
}  // namespace

namespace pachy {

Pachy::Pachy(const std::vector<std::string>& input_cli_args) : input_cli_args_{input_cli_args} {
}

int Pachy::execute() {
    int error_code_success{0};
    int error_code_failure{1};
    // Add flags
    auto status_add_flags = add_flags();
    if (status_add_flags.failure()) {
        std::cerr << status_add_flags.error_message() << std::endl;
        return error_code_failure;
    }
    // Parse cli args
    auto status_parse = arg_parser_.parse(input_cli_args_);
    if (status_parse.failure()) {
        std::cerr << status_parse.error_message() << std::endl;
        return error_code_failure;
    }
    // Version
    if (arg_parser_.is_flag_used(kVersionFlag.get_short())) {
        printer_.version();
        return error_code_success;
    }
    // Help
    if (arg_parser_.is_flag_used(kHelpFlag.get_short())) {
        printer_.help();
        return error_code_success;
    }
    // Parse YAML FILE
    auto status_yaml_parse = yaml_parser_.parse(); // Parse all files inside .pachy directory
    if (!status_yaml_parse.success()) {
        std::cerr << status_yaml_parse.error_message() << std::endl;
        return error_code_failure;
    }
    // Job : Run specified job
    if (arg_parser_.is_flag_used(kJobFlag.get_short())) {
        auto status_job_run = job_runner_.run();
        if (status_job_run.success()) {
            return error_code_success;
        } else {
            return error_code_failure;
        }
    }
    // Pipeline : Run specified pipeline.
    if (arg_parser_.is_flag_used(kPipelineFlag.get_short())) {
    }
    return error_code_success;
}

StatusCode Pachy::add_flags() {
    // Default Success status
    StatusCode status{};
    // Version
    status = arg_parser_.add_flag(kVersionFlag);
    if (status.failure()) {
        return status;
    }
    // Help
    status = arg_parser_.add_flag(kHelpFlag);
    if (status.failure()) {
        return status;
    }
    // Jobs
    status = arg_parser_.add_flag(kJobFlag);
    if (status.failure()) {
        return status;
    }
    // Pipeline
    status = arg_parser_.add_flag(kPipelineFlag);
    if (status.failure()) {
        return status;
    }
    return status;
}

}  // namespace pachy

