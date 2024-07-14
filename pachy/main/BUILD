load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_binary(
    name = "pachy",
    srcs = ["main.cpp"],
    deps = [
        "//pachy/main:pachylib"
    ],
)

cc_library(
    name = "pachylib",
    srcs = ["pachy.cpp"],
    hdrs = ["pachy.hpp"],
    deps = [
        "//pachy/arg_parser:arg_parser",
        "//pachy/runner:runner"
    ],
)
