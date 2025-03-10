#ifndef YAML_PARSER_FILE_HANDLER_HPP_
#define YAML_PARSER_FILE_HANDLER_HPP_


#include <memory>
#include <string>
#include <cstdio>

#include "pachy/error_handling/status_code.hpp"

namespace pachy {

class FilePointerDeleter {
  public:
    FilePointerDeleter() = default;
    void operator()(FILE* file);
    bool success() const;
  private:
    bool success_;

};

class FileHandler {
  public:
    FileHandler(const std::string& file_path);
    bool is_valid() const;
    FILE& get_file() const;
    StatusCode close_file();
  private:
    std::unique_ptr<FILE, ::pachy::FilePointerDeleter> file_;
};

}  // namespace pachy

#endif // YAML_PARSER_FILE_HANDLER_HPP_


