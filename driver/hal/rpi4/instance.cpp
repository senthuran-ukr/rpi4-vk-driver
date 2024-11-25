#include "instance.h"
#include "utils/log.h"
namespace core{

    VkResult InstanceVk::init(const VkAllocationCallbacks* pAllocator, VkInstanceCreateInfo* pInfo)
    {
        if(pInfo->enabledExtensionCount)
        {
            LOG_E("instance xtensions not supported");
            return  VK_ERROR_INITIALIZATION_FAILED
        }

        if(pInfo->enabledLayerCount)
        {
            LOG_E("instance layers not supported");
            return  VK_ERROR_INITIALIZATION_FAILED
        }
        if(pInfo->pApplicationInfo->apiVersion > core::API_VERSION)
        {
            LOG_E("unsupported api version");
            return  VK_ERROR_INITIALIZATION_FAILED
        }

        return DispatchableObjectPhysicalDevice::create(pAllocator, pInfo, m_physicalDevices);
    }
}