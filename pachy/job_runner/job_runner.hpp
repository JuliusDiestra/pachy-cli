/**
 * @file job_runner.hpp
 *
 */

#ifndef JOB_RUNNER_RUNNER_HPP_
#define JOB_RUNNER_RUNNER_HPP_

//#include "pachy/yaml_parser/yaml_parser.hpp"
#include "pachy/error_handling/status_code.hpp"

namespace pachy {

class JobRunner {
  public:
    JobRunner();
    pachy::StatusCode run();
  private:
    //pachy::YamlParser yaml_parser_;
};

}  // namespace pachy

#endif  // JOB_RUNNER_RUNNER_HPP_


