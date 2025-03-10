
#include "gtest/gtest.h"

#include "pachy/yaml_parser/file_handler.hpp"

namespace {
const std::string kFileLocation{"/tmp/workspace/pachy/yaml_parser/test/files/"};
const std::string kJobsFile{"jobs.yaml"};
}

TEST(FileHandler, Open_and_Close) {
    auto file = kFileLocation + kJobsFile;
    pachy::FileHandler file_handler(file);
    ASSERT_TRUE(file_handler.is_valid());
    auto status = file_handler.close_file();
    EXPECT_TRUE(status.success());
}

