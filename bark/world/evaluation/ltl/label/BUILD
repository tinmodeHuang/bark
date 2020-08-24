cc_library(
    name = "include",
    hdrs = [
        "evaluation_map.hpp",
        "label.h",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "label",
    srcs = ["evaluation_map.cpp"],
    hdrs = [
        "evaluation_map.hpp",
        "label.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//bark/world",
        "//bark/world/evaluation/ltl/label_functions:base_label_function",
        "@com_github_google_glog//:glog",
    ],
)
