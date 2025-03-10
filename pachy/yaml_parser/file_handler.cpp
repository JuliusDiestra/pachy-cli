
#include "file_handler.hpp"

#include <iostream>

namespace pachy {

void FilePointerDeleter::operator()(FILE* file) {
    success_ = (fclose(file) == 0);
}

bool FilePointerDeleter::success() const {
    return success_;
}

FileHandler::FileHandler(const std::string& file_path) {
    file_ = std::unique_ptr<std::FILE, pachy::FilePointerDeleter>(fopen(file_path.c_str(),"rb"));
}

bool FileHandler::is_valid() const {
    return (file_ != nullptr);
}

FILE& FileHandler::get_file() const {
    return *file_.get();
}

StatusCode FileHandler::close_file() {
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

