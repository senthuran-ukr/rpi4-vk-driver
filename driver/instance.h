#pragma once
#include <vulkan/vulkan.h>
#include "physical_device.h"
#include <vector>
#include <string>
namespace core
{
    class InstanceVk
    {
        public:
        InstanceVk(){}

        VkResult init(const VkAllocationCallbacks* pAllocator, VkInstanceCreateInfo* pInfo);

        VkResult enumeratePhysicalDevices(
        uint32_t*                                   pPhysicalDeviceCount,
        VkPhysicalDevice*                           pPhysicalDevices);

        private:
        PhysicalDeviceVk* m_physicalDevices = nullptr;

        VkApplicationInfo    mApplicationInfo;
        std::vector<std::string> mEnabledLayerNames;
        std::vector<std::string> mEnabledExtensionNames;


    };
}

