#pragma once
#include "logical_device.h"
namespace core{
    class PhysicalDeviceVk
    {
        public:
        PhysicalDeviceVk(){}
        VkResult init(const VkAllocationCallbacks*                pAllocator,
            VkInstanceCreateInfo*                                 pInstanceCreateInfo);
        VkResult createDevice(
            const VkDeviceCreateInfo*                   pCreateInfo,
            const VkAllocationCallbacks*                pAllocator,
            VkDevice*                                   pDevice);

        void getQueueFamilyProperties(  uint32_t pQueueFamilyPropertyCount,
                                        VkQueueFamilyProperties *pQueueFamilyProperties )const;

        LogicalDeviceVk* getLogicalDevice(uint32_t index);
        private:
        std::vector<LogicalDeviceVk*> mLogicalDevices;
        std::vector<VkQueueFamilyProperties> mQueueFamilyProperties;

        // void getPhysicalDeviceLimits(VkPhysicalDeviceLimit* outPhysicalDeviceLimit);
    };  
}