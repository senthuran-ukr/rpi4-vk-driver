#include "physical_device.h"
#include "base.h"
namespace core
{
VkResult VkPhysicalDevice_::createDevice(
    const VkDeviceCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDevice*                                   pDevice)
    {
        VkLogicalDevice_* logicalDevice = new VkLogicalDevice_();
        if(logicalDevice == nullptr)
            return VK_ERROR_OUT_OF_HOST_MEMORY;
            
        VkResult result = logicalDevice->init(pCreateInfo);
        if(result)return result;
        mLogicalDevices.push_back(logicalDevice);
        *pDevice = (VkDevice)logicalDevice;
        return VK_SUCCESS;
    }
}




extern "C"
{
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDevice(
    VkPhysicalDevice                            physicalDevice,
    const VkDeviceCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDevice*                                   pDevice)
    {
        core::VkPhysicalDevice_* corePhyDevice = CAST_TO_CORE(VkPhysicalDevice, physicalDevice);
        return corePhyDevice->createDevice(pCreateInfo, pAllocator, pDevice);
    }
}