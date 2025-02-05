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
    srcs = ["pachy.cpp",
            "printer.cpp"],
    hdrs = ["pachy.hpp",
            "printer.hpp"],
    deps = [
        "//pachy/arg_parser:arg_parser",
        "//pachy/error_handling:error_handling"
    ],
    visibility = ["//pachy/main/test:__pkg__"]
)
