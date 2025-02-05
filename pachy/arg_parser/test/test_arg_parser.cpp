
#include "gtest/gtest.h"
#include "pachy/arg_parser/arg_parser.hpp"

namespace {
const std::string v_short{"-v"};
const std::string v_long{"--v"};
const std::string v_des{"Version"};
const std::string h_short{"-h"};
const std::string h_long{"--h"};
const std::string h_des{"Help"};
}


TEST(ArgParser, Constructor_Default) {
    pachy::ArgParser arg_parser;
    EXPECT_EQ(0, arg_parser.size());
}

TEST(ArgParser, Add_Flag) {
    pachy::ArgParser arg_parser;
    // Add Version Flag
    pachy::Flag flag_version(v_short, v_long, v_des);
    auto status_code = arg_parser.add_flag(flag_version);
    EXPECT_EQ(1, arg_parser.size());
    EXPECT_TRUE(status_code.success());
    // Add Help Flag
    pachy::Flag flag_help(h_short, h_long, h_des);
    status_code = arg_parser.add_flag(flag_help);
    EXPECT_EQ(2, arg_parser.size());
    EXPECT_TRUE(status_code.success());
}

TEST(ArgParser, Add_Flag_Dupplicated) {
    pachy::ArgParser arg_parser;
    // Add Help Flag
    pachy::Flag flag_help(h_short, h_long, h_des);
    auto status_code = arg_parser.add_flag(flag_help);
    EXPECT_EQ(1, arg_parser.size());
    EXPECT_TRUE(status_code.success());
    // Add a duplicated flag
    pachy::Flag flag_dup_short(h_short, "--r", "Duplicated short flag");
    pachy::Flag flag_dup_long("-r", h_long, "Duplicated long flag");
    status_code = arg_parser.add_flag(flag_dup_short);
    EXPECT_FALSE(status_code.success());
    EXPECT_EQ(1, arg_parser.size());
    status_code = arg_parser.add_flag(flag_dup_long);
    EXPECT_EQ(1, arg_parser.size());
    EXPECT_FALSE(status_code.success());
}

