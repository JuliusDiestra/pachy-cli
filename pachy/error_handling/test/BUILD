load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "test_error_handling",
    srcs = glob(["*.cpp"]),
    linkopts = ["-lpthread"],
    deps = [
        "@external-libs//:libgtest",
        "@external-libs//:libgtest_main",
        "//pachy/error_handling:error_handling"
    ],
)

