#include "instance.h"
#include "caps.h"
#include "vkobject.h"
#include "utils/log.h"
namespace core{
VkResult InstanceVk::enumeratePhysicalDevices(
    uint32_t* pPhysicalDeviceCount,
    VkPhysicalDevice* pPhysicalDevices)
{
    if(pPhysicalDevices == nullptr)
    {
        *pPhysicalDeviceCount = 1;
    }
    else
    {
        // enumerate it
        pPhysicalDevices[1] = DispatchableObjectPhysicalDevice::cast(m_physicalDevices);
    }
    return VK_SUCCESS;
}
}


extern "C"
{
    VKAPI_ATTR VkResult VKAPI_CALL vkCreateInstance(
        const VkInstanceCreateInfo*                 pCreateInfo,
        const VkAllocationCallbacks*                pAllocator,
        VkInstance*                                 pInstance)
    {
        *pInstance = VK_NULL_HANDLE;
        VkResult result = core::DispatchableObject<VkInstance, core::InstanceVk>::create(pAllocator, pCreateInfo, pInstance);
        return result;
    }

    
VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDevices(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceCount,
    VkPhysicalDevice*                           pPhysicalDevices)
    {
        core::InstanceVk* coreInstance = CAST_TO_CORE(VkInstance, instance);
        return coreInstance->enumeratePhysicalDevices(pPhysicalDeviceCount, pPhysicalDevices);
    }
}