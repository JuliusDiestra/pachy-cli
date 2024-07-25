
#include "file_handler.hpp"
#include <iostream>

FileHandler::FileHandler(std::string file_path) {
    file_ = fopen(file_path.c_str(), "rb");
}

FileHandler::~FileHandler() {
    if (file_) {
        auto fclose_result = fclose(file_);
        if (fclose_result != 0) {
            std::cerr << "fclose function failed" << "\n";
        }
    }
}

FILE& FileHandler::GetFile() {
    return *file_;
}

