#pragma once
#include <stdlib.h>
#include "caps.h"

#define MAX_PHYSICAL_DEVICES 1

typedef struct VkPhysicalDevice_T
{
    struct Vk_Instance* instance;
}Vk_PhysicalDevice;

typedef struct VkInstance_T
{
    Vk_PhysicalDevice devices[MAX_PHYSICAL_DEVICES];
}Vk_Instance;

typedef struct VKDevice_T
{
    Vk_PhysicalDevice *pPhysicalDevice;
    uint32_t enabled_extensions_idx[NUM_DEVICE_EXTENSIONS];
    uint32_t num_enabled_extensions;
}Vk_Device;



#undef MAX_PHYSICAL_DEVICES
