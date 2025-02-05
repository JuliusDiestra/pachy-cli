load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "error_handling",
    srcs = ["exception.cpp",
            "status_code.cpp"],
    hdrs = ["exception.hpp",
            "status_return.hpp",
            "status_type.hpp",
            "status_code.hpp"],
    visibility = ["//pachy/error_handling/test:__pkg__",
                  "//pachy/main:__pkg__",
                  "//pachy/main/test:__pkg__",
                  "//pachy/arg_parser:__pkg__",
                  "//pachy/arg_parser/test:__pkg__",
                 ]
)
