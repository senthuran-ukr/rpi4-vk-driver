#include "pipeline.h"
namespace core{
VkResult PipelineVk::createGraphicsPipeline(LogicalDeviceVk* pDevice, const VkGraphicsPipelineCreateInfo* pPipelineInfo)
{
    PipelineVk* pPipeline = new GraphicsPipelineVk();
    if(pPipeline == nullptr)
    {
        return VK_ERROR_OUT_OF_HOST_MEMORY;
    }
    
}

}