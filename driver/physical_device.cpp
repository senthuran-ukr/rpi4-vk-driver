#include "physical_device.h"
#include "base.h"
#include "vkobject.h"
namespace core
{
VkResult PhysicalDeviceVk::createDevice(
    const VkDeviceCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDevice*                                   pDevice)
    {
        VkResult result = DispatchableObject::create(pAllocator, pCreateInfo, pDevice);
        if(result)
            return result;

        mLogicalDevices.push_back(*pDevice);
        return result;
    }

void PhysicalDeviceVk::getQueueFamilyProperties(uint32_t pQueueFamilyPropertyCount,
                                        VkQueueFamilyProperties *pQueueFamilyProperties )const
{
    ASSERT(pQueueFamilyPropertyCount != nullptr);
    if(pQueueFamilyProperties == nullptr)
    {
        *pQueueFamilyPropertyCount = mQueueFamilyProperties.size();
        return;
    }
    ASSERT(*pQueueFamilyPropertyCount <= mQueueFamilyProperties.size());
    for(uint32_t i = 0; i < *pQueueFamilyPropertyCount; ++i)
    {
        pQueueFamilyProperties[i] = mQueueFamilyProperties[i];
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
        core::PhysicalDeviceVk* phyDevice_ = core::DispatchableObject::cast(physicalDevice);
        return phyDevice_->createDevice(pCreateInfo, pAllocator, pDevice);
    }
}