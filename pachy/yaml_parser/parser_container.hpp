#ifndef YAML_PARSER_JOB_CONTAINER_HPP_
#define YAML_PARSER_JOB_CONTAINER_HPP_

#include "job_container.hpp"
#include "pipeline_container.hpp"

namespace pachy {

struct ParseContainer {
    ParseContainer() : job_container_{}, pipeline_container_{};
    JobContainer jobs_container;
    PipelineContainer pipeline_container;
};

}  // namepsace pachy

#endif // YAML_PARSER_JOB_CONTAINER_HPP_
