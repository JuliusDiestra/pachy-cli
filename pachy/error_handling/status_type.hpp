/**
 * @file status_type.hpp
 *
 */

#ifndef PACHY_ERROR_HANDLING_STATUS_TYPE_HPP_
#define PACHY_ERROR_HANDLING_STATUS_TYPE_HPP_

namespace pachy {

/**
 * @enum StatusType
 * @brief Enum to clasify different status. Including success status or runtime
 * errors.
 *
 */
enum class StatusType {
    kSuccess,               // Success status.
};

}  // namespace marsvin

#endif  // MARSVIN_CORE_MARSVIN_STATUS_TYPE_HPP_
