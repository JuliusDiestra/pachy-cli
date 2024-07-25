
#include "yaml_interface.hpp"
#include <iostream>

YamlInterface::YamlInterface(FILE& file) {
    yaml_parser_initialize(&yaml_parser_);
    yaml_parser_set_input_file(&yaml_parser_, &file);
}

YamlInterface::~YamlInterface() {
    yaml_parser_delete(&yaml_parser_);
}

bool YamlInterface::ScanFile(const std::vector<Job>& jobs) {
    if (!jobs.empty()) {
        return false;
    }
    bool status{true};
    int mapping_counter = 0;
    int sequence_counter = 0;
    bool is_jobs_started = false;
    bool start_storing_job = false;
    bool start_storing_job_element = false;
    int job_counter = 0;
    int scalar_counter = 0;
    bool store_name_flag = false;
    while(true) {
        UpdateEvent();
        PrintEvent();
        if (IsDone()) {
            break;
        }
        if (yaml_event_.type == YAML_MAPPING_START_EVENT) {
            ++mapping_counter;
        }
        if (yaml_event_.type == YAML_MAPPING_END_EVENT) {
            --mapping_counter;
        }
        if (yaml_event_.type == YAML_SEQUENCE_START_EVENT) {
            ++sequence_counter;
        }
        if (yaml_event_.type == YAML_SEQUENCE_END_EVENT) {
            --sequence_counter;
        }
        if (mapping_counter == 1) {
            if (yaml_event_.type == YAML_SCALAR_EVENT) {
                if ("jobs" == ScalarToString()) {
                    is_jobs_started = true;
                }
            }
        }
        if (is_jobs_started) {
            if (sequence_counter == 1) {
                // Jobs listing started.
                start_storing_job = true;
            }
            if (sequence_counter == 0) {
                // Jobs listing stopped.
                start_storing_job = false;
            }
        }
        // Storing name
        if (store_name_flag && (yaml_event_.type == YAML_SCALAR_EVENT)) {
            std::cout << "Job name : " << ScalarToString() << std::endl;
            store_name_flag = false;
        }
        // Storing jobs
        if (start_storing_job) {
            if (mapping_counter == 2) {
                start_storing_job_element = true;
                scalar_counter = 0;
            }
            if (mapping_counter < 2) {
                start_storing_job_element = false;
            }
        }
        if (start_storing_job_element) {
            if (yaml_event_.type == YAML_SCALAR_EVENT) {
                ++scalar_counter;
            }
            if (scalar_counter == 1) {
                if ("name" == ScalarToString()) {
                    store_name_flag = true;
                }
            }
        }

    }
    return status;
}

bool YamlInterface::UpdateEvent() {
    return (!yaml_parser_parse(&yaml_parser_, &yaml_event_));
}

std::string YamlInterface::ScalarToString() {
    if (yaml_event_.type == YAML_SCALAR_EVENT) {
        return std::string{reinterpret_cast<char*>(yaml_event_.data.scalar.value)};
    } else {
        return std::string{};
    }
}

bool YamlInterface::IsDone() {
    return (yaml_event_.type == YAML_STREAM_END_EVENT);
}

void YamlInterface::PrintEvent() const {
    switch (yaml_event_.type) {
        case YAML_NO_EVENT:
            std::cout << "YAML_NO_EVENT" << "\n";
            break;
        case YAML_STREAM_START_EVENT:
            std::cout << "YAML_STREAM_START_EVENT" << "\n";
            break;
        case YAML_STREAM_END_EVENT:
            std::cout << "YAML_STREAM_END_EVENT" << "\n";
            break;
        case YAML_DOCUMENT_START_EVENT:
            std::cout << "YAML_DOCUMENT_START_EVENT" << "\n";
            break;
        case YAML_DOCUMENT_END_EVENT:
            std::cout << "YAML_DOCUMENT_END_EVENT" << "\n";
            break;
        case YAML_ALIAS_EVENT:
            std::cout << "YAML_ALIAS_EVENT" << "\n";
            break;
        case YAML_SCALAR_EVENT:
            std::cout << "YAML_SCALAR_EVENT" << "\n";
            break;
        case YAML_SEQUENCE_START_EVENT:
            std::cout << "YAML_SEQUENCE_START_EVENT" << "\n";
            break;
        case YAML_SEQUENCE_END_EVENT:
            std::cout << "YAML_SEQUENCE_END_EVENT" << "\n";
            break;
        case YAML_MAPPING_START_EVENT:
            std::cout << "YAML_MAPPING_START_EVENT" << "\n";
            break;
        case YAML_MAPPING_END_EVENT:
            std::cout << "YAML_MAPPING_END_EVENT" << "\n";
            break;
        default:
            std::cout << "MISSING" << "\n";
            break;
    }
}
