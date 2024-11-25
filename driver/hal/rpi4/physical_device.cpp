#include "physical_device.h"
namespace core{
VkResult PhysicalDeviceVk::init(
    const VkAllocationCallbacks* pAllocator,
    VkInstanceCreateInfo* pInstanceCreateInfo)
    {
        mQueueFamilyProperties.resize(1);
        mQueueFamilyProperties[0].queueCount = 1;
        mQueueFamilyProperties[0].queueFlags = VK_QUEUE_COMPUTE_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_TRANSFER_BIT;
        mQueueFamilyProperties[0].timestampValidBits = 0;
        mQueueFamilyProperties[0].minImageTransferGranularity = VkExtent3D{0};

        return VK_SUCCESS;
    }



}