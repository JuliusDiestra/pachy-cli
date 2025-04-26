
#include "file_handler.hpp"

namespace pachy {

void FileHandler::FilePointerDeleter::operator()(FILE* file) {
    success_ = (fclose(file) == 0);
}

bool FileHandler::FilePointerDeleter::success() const {
    return success_;
}

FileHandler::FileHandler() : file_{nullptr}{
}

StatusCode FileHandler::open(const std::string& file_path) {
    // In case file is already open, close it and open the new one.
    if (file_) {
        auto status_close = close();
        if (status_close.failure()) {
            // Error while closing file
            return status_close;
        }
    }
    file_ = std::unique_ptr<std::FILE, FilePointerDeleter>(fopen(file_path.c_str(),"rb"));
    if (file_ == nullptr) {
        // Error while fopen fails
        return StatusCode{StatusType::kUnknownError};
    } else {
        return StatusCode{};
    }
}

bool FileHandler::is_valid() const {
    return (file_ != nullptr);
}

FILE& FileHandler::get_file() const {
    return *file_.get();
}

StatusCode FileHandler::close() {
    if (file_) {
        FILE* raw_pointer = file_.release();
        FilePointerDeleter deleter;
        deleter(raw_pointer);
        if (deleter.success()) {
            return StatusCode{};
        } else {
            return StatusCode{StatusType::kUnknownError};
        }
    }
    return StatusCode{};
}

}  // namespace pachy

