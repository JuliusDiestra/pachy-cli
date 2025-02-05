
#include "gtest/gtest.h"

#include "pachy/error_handling/status_return.hpp"

TEST(StatusReturn, Constructor_Value) {
    const int value {10};
    pachy::StatusReturn<int> status_return{value};
    EXPECT_TRUE(status_return.has_value());
    EXPECT_EQ(status_return.value(), value);
    EXPECT_TRUE(status_return.status_code().success());
}

TEST(StatusReturn, Constructor_StatusCode_kSuccess) {
    pachy::StatusCode status_code{};
    EXPECT_THROW(pachy::StatusReturn<int> status_return{status_code}, pachy::Exception);
}

TEST(StatusReturn, Constructor_StatusCode) {
    pachy::StatusCode status_code{pachy::StatusType::kRepeatedFlag};
    pachy::StatusReturn<int> status_return{status_code};
    EXPECT_EQ(status_code.status_type(), status_return.status_code().status_type());
    EXPECT_FALSE(status_return.has_value());
    EXPECT_THROW(status_return.value(), pachy::Exception);
}

