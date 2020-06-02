#pragma once
#include <stdlib.h>
#include "caps.h"

#define MAX_PHYSICAL_DEVICES 1
#define NUM_DEVICE_QUEUE_SUPPORTED 1
#define MAX_DEVICE_QUEUE_FAMILY_SUPPORTED 1


#define ASSERT(val, msg) assert(val) 

typedef struct VkPhysicalDevice_T
{
    struct Vk_Instance* instance;
}Vk_PhysicalDevice;

typedef struct VkInstance_T
{
    Vk_PhysicalDevice devices[MAX_PHYSICAL_DEVICES];
}Vk_Instance;

typedef struct VkQueue_T
{

}Vk_Queue;

typedef struct DeviceQueueFamily_T
{
    uint32_t num_queues;
    Vk_Queue queue[1];
    VkQueueFlagBits flags;
}DeviceQueueFamily;


typedef struct
{
    Vk_PhysicalDevice *pPhysicalDevice;
    uint32_t enabled_extensions_idx[NUM_DEVICE_EXTENSIONS];
    uint32_t num_enabled_extensions;

    VkPhysicalDeviceFeatures enabled_features;

    DeviceQueueFamily queue_family[MAX_DEVICE_QUEUE_FAMILY_SUPPORTED];

}Vk_Device;



#undef MAX_PHYSICAL_DEVICES
