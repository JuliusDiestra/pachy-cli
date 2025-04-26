#ifndef YAML_PARSER_FILE_SYSTEM_HANDLER_HPP_
#define YAML_PARSER_FILE_SYSTEM_HANDLER_HPP_

#include <filesystem>
#include <vector>

namespace pachy {

class FileSystemHandler {
  public:
    FileSystemHandler();
    bool pachy_dir_exists() const;
    std::vector<std::filesystem::path> get_file_paths();
  private:
    bool is_allowed_extension(const std::filesystem::path& extension) const;
};

}  // namespace pachy

#endif // YAML_PARSER_FILE_SYSTEM_HANDLER_HPP_

