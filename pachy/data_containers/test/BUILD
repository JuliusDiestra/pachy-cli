
load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "test_data_containers",
    srcs = glob(["*.cpp"]),
    linkopts = ["-lpthread"],
    size="small",
    deps = [
        "@external-libs//:libgtest",
        "@external-libs//:libgtest_main",
        "//pachy/data_containers:data_containers"
    ],
)
