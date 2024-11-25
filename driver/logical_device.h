#pragma one
#include "queue.h"
#include  "caps.h"
#include <map>
#include <vector>

namespace core
{
    class PhysicalDeviceVk;
    struct LogicalDeviceInfo
    {
        uint32_t enabledDeviceExtensionsIdx[NUM_DEVICE_EXTENSIONS];
        uint32_t numEnabledExtensions = 0;
        VkPhysicalDeviceFeatures enabledFeatures;
    };

    class LogicalDeviceVk
    {
        public:
        VkResult init(const VkAllocationCallbacks* pAllocator, const VkDeviceCreateInfo* pCreateInfo, PhysicalDeviceVk* phyDevice);
        VkQueue getQueue(uint32_t queueFamilyIndex, uint32_t queueIndex)const;
        
        VkResult createGraphicsPipeline(
            VkPipelineCache                             pipelineCache,
            uint32_t                                    createInfoCount,
            const VkGraphicsPipelineCreateInfo*         pCreateInfos,
            const VkAllocationCallbacks*                pAllocator,
            VkPipeline*                                 pPipeline);

        private:
        typedef std::map<uint32_t, std::vector<QueueVk*>>QueueFamily;
        QueueFamily mQueues;
        LogicalDeviceInfo mInfo;
    };
}