load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "yaml_parser",
    srcs = ["yaml_parser.cpp",
            "file_system_handler.cpp",
            "file_handler.cpp",
            ],
    hdrs = ["yaml_parser.hpp",
            "file_system_handler.hpp",
            "file_handler.hpp",
            ],
    deps = [
        "//pachy/error_handling:error_handling"
    ],
    visibility = ["//pachy/main:__pkg__",
                  "//pachy/yaml_parser/test:__pkg__"]
)
