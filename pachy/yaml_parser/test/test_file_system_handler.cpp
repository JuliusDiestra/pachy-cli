
#include "gtest/gtest.h"

#include "pachy/yaml_parser/file_system_handler.hpp"

namespace {
const std::filesystem::path kPachyDirectory{".pachy"};
const std::filesystem::path kCurrentPath{std::filesystem::current_path()};
const std::filesystem::path kPachyDirPath{kCurrentPath/kPachyDirectory};
}  // namespace

class FileSystemHandlerTest : public ::testing::Test {
  public:
    virtual void SetUp() override {
        // Check if .pachy dir exists
        // Remove .pachy if exists
        remove_pachy_dir();
    }
    virtual void TearDown() override {
        // Remove .pachy if exists
        remove_pachy_dir();
    }
  protected:
    pachy::FileSystemHandler file_system_handler_;
    void remove_pachy_dir() {
        auto pachy_dir_exists = std::filesystem::is_directory(kPachyDirPath);
        if (pachy_dir_exists) {
            std::filesystem::remove(kPachyDirPath);
        }
    }
    void create_pachy_dir() {
        // Create .pachy fir in BIN_DIR
    }
    void add_yaml_files() {
        // Add yaml files in .pachy directory
    }
};

TEST_F(FileSystemHandlerTest, CheckIfPachyDirExists) {
    // check if .pachy dir exists
    EXPECT_FALSE(file_system_handler_.pachy_dir_exists());
}

