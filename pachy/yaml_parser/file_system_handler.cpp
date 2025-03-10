
#include "file_system_handler.hpp"

namespace {
const std::filesystem::path kPachyDirectory{".pachy"};
const std::filesystem::path kCurrentPath{std::filesystem::current_path()};
const std::filesystem::path kPachyDirPath{kCurrentPath/kPachyDirectory};
const std::filesystem::path kYamlExtension{".yaml"};
const std::filesystem::path kYmlExtension{".yml"};
const std::array<std::filesystem::path, 2> kAllowedExtensions{{kYamlExtension, kYmlExtension}};
}  // namespace

namespace pachy {

FileSystemHandler::FileSystemHandler() {};

bool FileSystemHandler::pachy_dir_exists() const {
    return std::filesystem::is_directory(kPachyDirPath);
}

std::vector<std::filesystem::path> FileSystemHandler::get_file_paths() {
    std::vector<std::filesystem::path> file_paths{};
    if (!pachy_dir_exists()) {
        return file_paths;
    }
    for (auto const& dir_entry : std::filesystem::directory_iterator{kPachyDirPath}) {
        auto extension = dir_entry.path().extension();
        if (is_allowed_extension(extension)) {
            file_paths.push_back(dir_entry);
        }
    }
    return file_paths;
}

bool FileSystemHandler::is_allowed_extension(const std::filesystem::path& extension) const{
    bool result = false;
    for (std::size_t j{0}; j < kAllowedExtensions.size(); ++j) {
        if (extension == kAllowedExtensions.at(j)) {
            result = true;
            break;
        }
    }
    return result;
}


}  // namespace pachy
