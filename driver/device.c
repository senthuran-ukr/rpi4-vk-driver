#include <vulkan/vulkan.h>
#include "common.h"

VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDevices(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceCount,
    VkPhysicalDevice*                           pPhysicalDevices)
{
    assert(instance);
    assert(pPhysicalDeviceCount);

    int num_gpus = 1;
    if(pPhysicalDevices == NULL)
    {
        *pPhysicalDeviceCount = num_gpus;
        return VK_SUCCESS;
    }

    for(int i = 0; i < num_gpus; ++i)
    {
        pPhysicalDevices[i] = &instance->devices[i]
    }
    *pPhysicalDeviceCount = num_gpus;
    return VK_SUCCESS;
}




