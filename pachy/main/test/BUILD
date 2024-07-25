load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "test_pachy",
    srcs = glob(["*.cpp"]),
    linkopts = ["-lpthread"],
    deps = [
        "@external-libs//:libgtest",
        "@external-libs//:libgmock",
        "@external-libs//:libgtest_main",
        "//pachy/main:pachylib"
    ],
)

