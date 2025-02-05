
#include "printer.hpp"

#include <iostream>

namespace {
const std::string kVersion = "1.0.0";
const std::string kMainHelpMenu =
    R"(
OVERVIEW: A tool to execute jobs (set of commands) and pipelines (set of jobs)
using command line. Jobs and pipelines must be defined in a YAML document.

Usage: pachy [FLAG] [JOB_NAME...]
       pachy [FLAG] [PIPELINE_NAME]
       pachy [FLAG]
       pachy [GENERIC FLAG]

    pachy --help
    pachy --version
    pachy --run job_one job_two
    pachy --run pipeline_name

Flags:
  -r,   --run               Run specified jobs or single pipeline.

Generic Flags:
  -h, --help        Display help menu.
  -v, --version     Display version.

)";
}

namespace pachy {

void Printer::help() const {
    std::cout << kMainHelpMenu;
}
void Printer::version() const {
    std::cout << "pachy version " << kVersion << "\n";
}

}  // namespace pachy
