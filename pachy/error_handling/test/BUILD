load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "test_error_handling",
    srcs = glob(["*.cpp"]),
    linkopts = ["-lpthread"],
    size="small",
    deps = [
        "@external-libs//:libgtest",
        "@external-libs//:libgtest_main",
        "//pachy/error_handling:error_handling"
    ],
)

