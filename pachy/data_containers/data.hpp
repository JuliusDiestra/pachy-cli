#ifndef DATA_CONTAINERS_DATA_HPP_
#define DATA_CONTAINERS_DATA_HPP_

#include <cstdint>

#include "pachy/error_handling/status_code.hpp"
#include "job_container.hpp"
#include "pipeline_container.hpp"

namespace pachy {

class Data {
  public:
    Data();
    StatusCode add(const Data& data);
    std::size_t job_numbers() const;
    std::size_t pipeline_numbers() const;
  private:
    JobContainer job_container_;
    PipelineContainer pipeline_container_;
};

}  // namepsace pachy

#endif // DATA_CONTAINERS_DATA_HPP_
