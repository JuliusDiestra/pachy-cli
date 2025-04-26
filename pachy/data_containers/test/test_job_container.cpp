
#include "gtest/gtest.h"

#include "pachy/data_containers/job_container.hpp"

TEST(JobContainerTest, DefaultConstructor) {
    pachy::JobContainer cut;
    EXPECT_EQ(cut.size(), 0);
}

TEST(JobContainerTest, AddMultipleJobs) {
    pachy::JobContainer cut;
    pachy::Job job_one;
    job_one.name = "one";
    pachy::Job job_two;
    job_two.name = "two";
    auto add_status = cut.add(job_one);
    EXPECT_TRUE(add_status.success());
    add_status = cut.add(job_two);
    EXPECT_TRUE(add_status.success());
    EXPECT_EQ(cut.size(), 2);
}

TEST(JobContainerTest, Duplicated) {
    pachy::JobContainer cut;
    pachy::Job job_one;
    job_one.name = "one";
    pachy::Job job_two;
    job_two.name = "one";
    auto add_status_one = cut.add(job_one);
    EXPECT_TRUE(add_status_one.success());
    auto add_status_two = cut.add(job_two);
    EXPECT_FALSE(add_status_two.success());
    EXPECT_EQ(cut.size(), 1);
}

