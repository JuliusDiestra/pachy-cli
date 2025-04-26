

#include "job_container.hpp"

namespace pachy {

bool JobContainer::Compare::operator()(const Job& rhs, const Job& lhs) const {
    return (rhs.name.compare(lhs.name) != 0);
}

StatusCode JobContainer::add(const Job& job) {
    const auto result_insert = jobs_.insert(job);
    if (!result_insert.second) {
        // Error if a job with duplicated name is detected
        return StatusCode{StatusType::kUnknownError};
    }
    return StatusCode{};
}

std::size_t JobContainer::size() const {
    return jobs_.size();
}

}  // namepsace pachy
