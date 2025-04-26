
#include "data.hpp"

namespace pachy {

Data::Data() : job_container_{}, pipeline_container_{} {}

StatusCode Data::add(const Data& data) {
    return StatusCode{};
}

std::size_t Data::job_numbers() const {
    return job_container_.size();
}

std::size_t Data::pipeline_numbers() const {
    return pipeline_container_.size();
}

}  // namepsace pachy
