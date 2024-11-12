#pragma once
#include <stdlib.h>
#include  <vulkan/vulkan.h>

#define CAST_TO_CORE(type, ptr) (core::##type##_*)ptr;

#define ASSERT(val, msg) assert(val) 

