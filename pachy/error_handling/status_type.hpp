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
    kSuccess,                       // Success status.
    kStatusReturnConstructor,       // StatusReturn constructor only accepts StatusCode for Error.
    kStatusReturnNoValue,           // StatusReturn does not contain value.
    kArgumentNotSupported,          // Arguments are not supported for an specific flag.
    kArgumentMaxNumber,             // Pass max number of arguments allowed.
    kRepeatedFlag,                  // Flag added is reaped. This means the flag was already added.
    kFlagDoesNotExist               // Flag does not exists inside Arguments class.
};

}  // namespace marsvin

#endif  // MARSVIN_CORE_MARSVIN_STATUS_TYPE_HPP_
