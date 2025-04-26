
#include "gtest/gtest.h"

#include "pachy/yaml_parser/job_container.hpp"

TEST(JobContainerTest, DefaultConstructor) {
    pachy::JobContainer job_container_;
    EXPECT_EQ(job_container_.size(), 0);
}
