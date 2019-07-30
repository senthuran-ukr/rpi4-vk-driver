cmake_minimum_required (VERSION 3.0)

file(GLOB src
        "*.h"
        "*.c"
)

add_library(libvulkan-rpi4 SHARED ${src})
target_compile_options(libvulkan-rpi4 PRIVATE -Wall -Werror=implicit-function-declaration -std=c11)
