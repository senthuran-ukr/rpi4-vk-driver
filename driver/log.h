#pragma once
#include <stdio.h>
#define LOG_DEBUG(x, ...) printf(("VK_DRIVER_DEBUG:"#x), __VA_ARGS__)
