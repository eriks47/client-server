cc_library(
    name = "common",
    srcs = glob(["src/*.cpp", "include/*.h"]),
    hdrs = glob(["include/*.h"]),
    includes = ["include"],
    linkopts = ["-lSDL2"],
    visibility = ["//server:__pkg__", "//client:__pkg__"],
)
