
#include "gtest/gtest.h"
#include <string>
#include "pachy/arg_parser/flag.hpp"
#include "pachy/error_handling/status_code.hpp"

namespace {
std::string short_flag{"-t"};
std::string long_flag{"--test"};
std::string description{"Test."};
}

std::vector<std::string> ArgFactory(std::size_t nbr_of_flags) {
    std::vector<std::string> arg_vector;
    std::string base_flag{"flag_arg_"};
    for (std::size_t j{0}; j < nbr_of_flags; ++j) {
        std::string flag_arg{};
        flag_arg.append(base_flag);
        flag_arg.append(std::to_string(j));
        arg_vector.push_back(flag_arg);
    }
    return arg_vector;
}

TEST(Flag, Constructor_Boolean) {
    pachy::Flag flag{short_flag, long_flag, description};
    EXPECT_EQ(short_flag, flag.get_short());
    EXPECT_EQ(long_flag, flag.get_long());
}

TEST(Flag, IsUsed_SetUsed) {
    pachy::Flag flag{short_flag, long_flag, description};
    EXPECT_FALSE(flag.is_used());
    flag.set_used();
    EXPECT_TRUE(flag.is_used());
}

TEST(Flag, AppendArg_Error_NotAllowed) {
    pachy::Flag flag{short_flag, long_flag, description};
    std::string flag_arg{"flag_arg"};
    auto status_code = flag.append_arg(flag_arg);
    EXPECT_TRUE(status_code.failure());
    EXPECT_EQ(status_code.status_type(), pachy::StatusType::kArgumentNotSupported);
}

TEST(Flag, AppendArg_Error_MaxArg) {
    std::size_t flag_max_args{10};
    std::size_t flag_args_created{flag_max_args+3};
    pachy::Flag flag{short_flag, long_flag, description, false, flag_max_args};
    std::vector<std::string> expected_args = ArgFactory(flag_args_created);
    pachy::StatusCode status_code;
    // Verification
    for (std::size_t j{0}; j < expected_args.size(); ++j) {
        status_code = flag.append_arg(expected_args.at(j));
        if (j < flag_max_args) {
            EXPECT_TRUE(status_code.success());
        } else {
            EXPECT_TRUE(status_code.failure());
            EXPECT_EQ(status_code.status_type(), pachy::StatusType::kArgumentMaxNumber);
        }
    }
}

TEST(Flag, AppendArg_GetArgs_Successful) {
    const std::size_t nbr_of_flags{10};
    std::vector<std::string> expected_args = ArgFactory(nbr_of_flags);
    pachy::Flag flag{short_flag, long_flag, description, false, nbr_of_flags};
    std::vector<pachy::StatusCode> status_code_vector;
    status_code_vector.reserve(nbr_of_flags);
    // Append args
    for (std::size_t j{0}; j < nbr_of_flags; ++j) {
        auto status_code_append = flag.append_arg(expected_args.at(j));
        EXPECT_TRUE(status_code_append.success());
    }
    // Verification
    auto args = flag.get_args();
    EXPECT_EQ(args.size(), nbr_of_flags);
    for (std::size_t j{0}; j < nbr_of_flags; ++j) {
        EXPECT_EQ(args.at(j).compare(expected_args.at(j)), 0);
    }
}

