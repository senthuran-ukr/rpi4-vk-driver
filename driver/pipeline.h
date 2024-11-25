#pragma once
#include <vulkan/vulkan.h>
#include <string>
#include <vector>
namespace core{

    class LogicalDeviceVk;
    class PipelineVk
    {
        public:
        PipelineVk(){}
        static VkResult createGraphicsPipeline(LogicalDeviceVk* pDevice, const VkGraphicsPipelineCreateInfo* pPipelineInfo);

        private:
        enum 
        {
            PIPELINE_TYPE_UNKNOWN = 0,
            PIPELINE_TYPE_GRAPHICS = 1,
            PIPELINE_TYPE_COMPUTE = 2
        } m_pipelineType; 

        struct 
        {
            // Graphics State
            std::string vertShaderName;
            std::string fragShaderName;
            std::vector<VkVertexInputBindingDescription> vertexBindingDescriptions;
            std::vector<VkVertexInputAttributeDescription>    vertexAttributeDescriptions;
            VkPrimitiveTopology                        topology;
            VkBool32                                   primitiveRestartEnable;

        
            std::vector<VkViewport>     viewports;
            std::vector<VkRect2D>       cissors;

        }m_info;
    };
}