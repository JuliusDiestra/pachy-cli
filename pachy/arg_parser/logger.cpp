
#include "logger.hpp"

#include <iostream>

namespace {
const std::string kVersion = "1.0.0";
const std::string kMainHelpMenu =
    R"(
OVERVIEW: A tool to execute jobs (set of commands) and pipelines (set of jobs)
using command line. Jobs and pipelines must be defined in a YAML document.

Usage: pachy [FLAG] [JOB_NAME]
       pachy [FLAG] [PIPELINE_NAME]
       pachy [FLAG]
       pachy [GENERIC FLAG]

    pachy --help
    pachy --version
    pachy --run job_one

Flags:
  -r,   --run               Run specified jobs or single pipeline.
  -d,   --deps              Flag to run jobs with its dependencies and
                            transitive dependencies. Must be use with --run.
  -sh,  --shell             Start docker shell with job docker image.
  -sd,  --show-deps         Show job dependencies.
  -sj,  --show-jobs         Show jobs in the project.
  -sp,  --show-pipelines    Show pipelines in the project.
  -val, --validate          Validate jobs and/or pipeline configuration.

Generic Flags:
  -h, --help        Display help menu.
  -v, --version     Display version.

)";
}

namespace pachy {

void Logger::PrintHelp() const {
    std::cout << kMainHelpMenu;
}
void Logger::PrintVersion() const {
    std::cout << "pachy version " << kVersion << "\n";
}

}  // namespace pachy
