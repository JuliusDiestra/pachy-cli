
#include "pipeline_container.hpp"

namespace pachy {

StatusCode PipelineContainer::add(const Pipeline& pipeline) {
    return StatusCode{};
}

std::size_t PipelineContainer::size() const {
    return pipelines_.size();
}

}  // namepsace pachy
