#ifndef DATA_CONTAINERS_PIPELINE_CONTAINER_HPP_
#define DATA_CONTAINERS_PIPELINE_CONTAINER_HPP_

#include <cstdint>
#include <set>

#include "pipeline.hpp"
#include "pachy/error_handling/status_code.hpp"

namespace pachy {

class PipelineContainer {
  public:
    PipelineContainer() = default;
    StatusCode add(const Pipeline& pipeline);
    std::size_t size() const;
  private:
    std::set<Pipeline> pipelines_;
};

}  // namepsace pachy

#endif // DATA_CONTAINERS_PIPELINE_CONTAINER_HPP_

