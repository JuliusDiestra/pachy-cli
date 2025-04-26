load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "data_containers",
    srcs = ["data.cpp",
            "job_container.cpp",
            "pipeline_container.cpp",
            ],
    hdrs = ["data.hpp",
            "job.hpp",
            "job_container.hpp",
            "pipeline.hpp",
            "pipeline_container.hpp",
            ],
    deps = [
        "//pachy/error_handling:error_handling"
    ],
    visibility = ["//pachy/yaml_parser:__pkg__",
                  "//pachy/data_containers/test:__pkg__"]
)
