#pragma once
#include <vulkan/vulkan.h>
#include "physical_device.h"
#include <vector>
#include <string>
namespace core
{
    class VkInstance_
    {
        public:
        VkInstance_(){}
        VkResult init(const VkInstanceCreateInfo* createInfo);

        VkResult enumeratePhysicalDevices(
        uint32_t*                                   pPhysicalDeviceCount,
        VkPhysicalDevice*                           pPhysicalDevices);

        private:
        std::vector<PhysicalDevice_> m_physicalDevices;

        VkApplicationInfo    mApplicationInfo;
        std::vector<std::string> mEnabledLayerNames;
        std::vector<std::string> mEnabledExtensionNames;


    };
}

