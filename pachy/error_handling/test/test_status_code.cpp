
#include "gtest/gtest.h"
#include "pachy/error_handling/status_code.hpp"
#include "pachy/error_handling/status_type.hpp"

class StatusCodeTestParam : public ::testing::TestWithParam<pachy::StatusType> {};

TEST_P(StatusCodeTestParam, Constructor_DefaultSuccess_And_SetStatusType) {
    pachy::StatusCode cut;
    EXPECT_EQ(cut.status_type(), pachy::StatusType::kSuccess);
    EXPECT_TRUE(cut.success());
    EXPECT_FALSE(cut.failure());
    pachy::StatusType status_type{GetParam()};
    cut.set_status_type(status_type);
    EXPECT_EQ(cut.status_type(), status_type);
    EXPECT_FALSE(cut.success());
    EXPECT_TRUE(cut.failure());
}

TEST_P(StatusCodeTestParam, TestStatusTypeError) {
    auto status_type = GetParam();
    pachy::StatusCode cut(status_type);
    EXPECT_EQ(cut.status_type(), status_type);
    EXPECT_FALSE(cut.success());
    EXPECT_TRUE(cut.failure());
    EXPECT_FALSE(cut.error_message().empty());
}

INSTANTIATE_TEST_CASE_P(
    StatusCodeErrorTests,
    StatusCodeTestParam,
    ::testing::Values(
         pachy::StatusType::kArgumentNotSupported,
         pachy::StatusType::kArgumentMaxNumber
    )
);

