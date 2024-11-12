#pragma once
#include "logical_device.h"
namespace core{
    class VkPhysicalDevice_
    {
        public:

        VkResult createDevice(
            const VkDeviceCreateInfo*                   pCreateInfo,
            const VkAllocationCallbacks*                pAllocator,
            VkDevice*                                   pDevice);

        VkLogicalDevice_* getLogicalDevice(uint32_t index);
        private:
        std::vector<VkLogicalDevice_*> mLogicalDevices;
        // void getPhysicalDeviceLimits(VkPhysicalDeviceLimit* outPhysicalDeviceLimit);
    };  
}