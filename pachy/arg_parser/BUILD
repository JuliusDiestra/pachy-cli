load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "arg_parser",
    srcs = ["arg_parser.cpp",
            "flag.cpp"],
    hdrs = ["arg_parser.hpp",
            "flag.hpp"],
    deps = [
        "//pachy/error_handling:error_handling"
    ],
    visibility = ["//pachy/main:__pkg__",
                  "//pachy/arg_parser/test:__pkg__"]
)
