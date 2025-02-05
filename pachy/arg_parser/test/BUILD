load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "test_arg_parser",
    srcs = glob(["*.cpp"]),
    linkopts = ["-lpthread"],
    deps = [
        "@external-libs//:libgtest",
        "@external-libs//:libgtest_main",
        "//pachy/arg_parser:arg_parser",
        "//pachy/error_handling:error_handling"
    ],
)
