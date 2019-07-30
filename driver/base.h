#pragma once
#include <stdlib.h>


#define MAX_PHYSICAL_DEVICES 1

#define UNUSED_VARIABLE(var) (void)var

#define ALLOC(size, alignment, scope) malloc(size)

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
}Vk_Device;



#undef MAX_PHYSICAL_DEVICES
