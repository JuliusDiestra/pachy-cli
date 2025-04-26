#ifndef DATA_CONTAINERS_JOB_CONTAINER_HPP_
#define DATA_CONTAINERS_JOB_CONTAINER_HPP_

#include <cstdint>
#include <set>

#include "job.hpp"
#include "pachy/error_handling/status_code.hpp"

namespace pachy {

class JobContainer {
  public:
    JobContainer() = default;
    StatusCode add(const Job& job);
    std::size_t size() const;
  private:
    struct Compare {
        bool operator()(const Job& rhs, const Job& lhs) const;
    };
    std::set<Job, Compare> jobs_;
};

}  // namepsace pachy

#endif // DATA_CONTAINERS_JOB_CONTAINER_HPP_

