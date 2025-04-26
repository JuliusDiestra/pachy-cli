load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "test_yaml_parser",
    srcs = glob(["*.cpp"]),
    linkopts = ["-lpthread"],
    size="small",
    deps = [
        "@external-libs//:libgtest",
        "@external-libs//:libgtest_main",
        "//pachy/yaml_parser:yaml_parser"
    ],
)
