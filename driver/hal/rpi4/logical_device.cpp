#include "logical_device.h"
#include "physical_device.h"
#include "base.h"
#include "vkobject.h"
namespace core{
    VkResult LogicalDeviceVk::init(
    const VkAllocationCallbacks*                pAllocator,
    const VkDeviceCreateInfo*                   pCreateInfo,
    PhysicalDeviceVk*                           pPhyDevice)
{
    UNUSED_VARIABLE(pAllocator);

    ASSERT(pCreateInfo, "pCreateInfo device must be valid");

    // Process supported extensions
    if(pCreateInfo->enabledExtensionCount)
    {
        LOG_E("device extensions not supported");
        return VK_ERROR_INITIALIZATION_FAILED;
    }
    if(pCreateInfo->enabledLayerCount)
    {
        LOG_E("device layers not supported");
        return VK_ERROR_INITIALIZATION_FAILED;
    }
    

    // @TODO Process supported Layers
    if(pCreateInfo->pEnabledFeatures)
    {
        memcpy(&mInfo.enabledFeatures, pCreateInfo->pEnabledFeatures, sizeof(VkPhysicalDeviceFeatures));
        update_device_feature(&mInfo.enabledFeatures);
    }

    if(pCreateInfo->pQueueCreateInfos)
    {
        for(uint32_t i = 0; i < pCreateInfo->queueCreateInfoCount; ++i)
        {
            const VkDeviceQueueCreateInfo* queue_info = &pCreateInfo->pQueueCreateInfos[i];
            for(uint32_t j = 0; j < queue_info->queueCount; ++j)
            {   
                QueueVk* queue = nullptr;
                VkResult result = DispatchableObjectQueue::create(pAllocator, pCreateInfo, queue, queue_info->queueFamilyIndex, queue_info->pQueuePriorities[j]);
                if(result)
                    return result;
                mQueues.push_back(queue);
            }
        }
    }
    return VK_SUCCESS;
}
}