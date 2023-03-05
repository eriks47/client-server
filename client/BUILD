cc_binary(
    name = "client",
    srcs = glob(["src/*.cpp", "include/*.h"]),
    includes = ["include"],
    deps = ["//common:common"],
    linkopts = ["-lSDL2", "-lSDL2_ttf", "-lSDL2_image"]
)
