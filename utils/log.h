#pragma once
#include <stdio.h>
#define LOG_D(x, ...) printf(("VK_DRIVER_DEBUG:"#x), __VA_ARGS__)
#define LOG_E(x, ...) printf(("VK_DRIVER_ERROR:"#x), __VA_ARGS__)
