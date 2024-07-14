load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "arg_parser",
    srcs = ["parser.cpp",
            "logger.cpp"],
    hdrs = ["parser.hpp",
            "logger.hpp"],
    visibility = ["//pachy/main:__pkg__",
                  "//pachy/runner:__pkg__"]
)
