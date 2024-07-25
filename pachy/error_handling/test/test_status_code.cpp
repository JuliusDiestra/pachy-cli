
#include "gtest/gtest.h"
#include "pachy/error_handling/status_code.hpp"
#include "pachy/error_handling/status_type.hpp"

TEST(StatusCode, Constructor_DefaultSuccess) {
    pachy::StatusCode cut;
    EXPECT_EQ(cut.status_type(), pachy::StatusType::kSuccess);
    EXPECT_TRUE(cut.success());
    EXPECT_FALSE(cut.failure());
}

