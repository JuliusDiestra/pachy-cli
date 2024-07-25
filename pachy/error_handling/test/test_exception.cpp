
#include "gtest/gtest.h"
#include "pachy/error_handling/exception.hpp"

TEST(Exception, Constructor_kSuccess) {
    EXPECT_THROW(pachy::Exception cut(pachy::StatusType::kSuccess), std::invalid_argument);
}

