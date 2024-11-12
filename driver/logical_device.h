#pragma one
#include "queue.h"
#include  "caps.h"
#include <vector>
namespace core
{

    struct LogicalDeviceInfo
    {
        uint32_t enabledDeviceExtensionsIdx[NUM_DEVICE_EXTENSIONS];
        uint32_t numEnabledExtensions = 0;
        VkPhysicalDeviceFeatures enabledFeatures;
    };



    class VkLogicalDevice_
    {
        public:
        VkResult init(const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks*                pAllocator);
        

        private:
            struct QueueInfo
    {

    };

        std::vector<VkQueue_> mQueues;
        LogicalDeviceInfo mInfo;
    };
}