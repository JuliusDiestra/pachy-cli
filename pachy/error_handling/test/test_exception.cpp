
#include "gtest/gtest.h"
#include "pachy/error_handling/exception.hpp"
#include "pachy/error_handling/status_code.hpp"

TEST(Exception, Constructor_kSuccess) {
    pachy::StatusCode status_code;
    EXPECT_THROW(pachy::Exception cut(status_code), std::invalid_argument);
}

TEST(Exception, Constructor_Error) {
    pachy::StatusType status_type{pachy::StatusType::kArgumentNotSupported};
    pachy::StatusCode status_code(status_type);
    pachy::Exception cut(status_code);
    EXPECT_EQ(cut.status_code().status_type(), status_type);
}

