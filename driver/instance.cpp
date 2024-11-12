#include "instance.h"
#include "caps.h"
namespace core{
    VkResult VkInstance_::enumeratePhysicalDevices(
        uint32_t* pPhysicalDeviceCount,
        VkPhysicalDevice* pPhysicalDevices)
        {
            if(pPhysicalDevices == nullptr)
            {
                *pPhysicalDeviceCount = limits::MAX_PHYSICAL_DEVICE;
            }
            else if(m_physicalDevices.size())// already enumerated?
            {
                for(uint32_t i = 0; i < m_physicalDevices.size(); ++i)
                {
                    pPhysicalDevices[i] = (VkPhysicalDevice)&m_physicalDevices[i];
                }
            }
            else
            {
                // enumerate it
                m_physicalDevices.resize(limits::MAX_PHYSICAL_DEVICE);
                for(uint32_t i = 0; i < limits::MAX_PHYSICAL_DEVICE; ++i)
                {
                    m_physicalDevices[i] = PhysicalDevice_();
                }
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
        auto coreInstance = new core::VkInstance_();
        VkResult result;
        if((result = coreInstance->init(pCreateInfo)) != VK_SUCCESS)
        {
            return result;
        }
        *pInstance = (VkInstance)coreInstance;
        return result;
    }

    
VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDevices(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceCount,
    VkPhysicalDevice*                           pPhysicalDevices)
    {
        core::VkInstance_* coreInstance = CAST_TO_CORE(VkInstance, instance);
        return coreInstance->enumeratePhysicalDevices(pPhysicalDeviceCount, pPhysicalDevices);
    }
}