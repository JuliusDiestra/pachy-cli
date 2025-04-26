load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "job_runner",
    srcs = ["job_runner.cpp"],
    hdrs = ["job_runner.hpp"],
    deps = [
        "//pachy/error_handling:error_handling"
    ],
    visibility = ["//pachy/main:__pkg__"]
)
