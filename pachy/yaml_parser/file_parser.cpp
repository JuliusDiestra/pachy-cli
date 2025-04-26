

#include "file_parser.hpp"

namespace {

const std::set<std::string> kValidKeys = {"jobs",
                                          "name",
                                          "docker-file",
                                          "run",
                                          "cmd",
                                          "vars"};

}  // namespace



StatusReturn<Data> FileParser::parse(FILE& file) {
    // Init parser
    const auto yaml_init_status = yaml_parser_initialize(&yaml_parser_);
    if(yaml_init_status != 1) {
        // Return error when yaml_parser_initialize failed.
        return StatusReturn<Data>(StatusCode{StatusType::kUnknownError});
    }
    // Start parser
    Job job;
    Pipeline pipeline;

    bool in_jobs_section{false};
    bool in_run_section{false};
    bool in_vars_section{false};

    std::string current_var_key;

    JobContainer job_container;
    PipelineContainer pipeline_container;

    while (true) {
        if (!yaml_parser_parse(&yaml_parser_, &yaml_event_)) {
            yaml_parser_delete(&parser);
            // Error parsing
            return StatusReturn<Data>(StatusCode{StatusType::kUnknownError});
        }
        switch(yaml_event_.type) {
            // When yaml start, we keep going.
            case (YAML_MAPPING_START_EVENT):
                break;
            case (YAML_MAPPING_END_EVENT):
                // if job name empty, means has not been filled.
                if (!job.name.empty()) {
                    auto status_add_job = job_container.add(job);
                    if (status_add_job.failure()) {
                        yaml_event_delete(&yaml_event_);
                        yaml_parser_delete(&yaml_parser_);
                        return StatusReturn<Data>(status_add_job);
                    }
                    job = Job{};

                }
                break;
            case (YAML_SCALAR_EVENT):
                std::string key = reinterpret_cast<char*>(yaml_event_.data.scalar.value);
                if (kValidKeys.find(key) == kValidKeys.end()) {
                    yaml_event_delete(&yaml_event_);
                    yaml_parser_delete(&yaml_parser_);
                    // Error unknown key.
                    return StatusReturn<Data>(StatusCode{StatusType::kUnknownError});
                }
                // more
            case (YAML_STREAM_END_EVENT):
                    yaml_event_delete(&yaml_event_);
                    yaml_parser_delete(&yaml_parser_);
                    // Return data
                    Data data(job,pipeline);
                    return StatusReturn<Data>(data);
                default:
                    break;
        }
        yaml_event_delete(&yaml_event_);
    }

    // Close parser
    // NOTE: Maybe not needed.
    yaml_parser_delete(&yaml_parser_);
}

