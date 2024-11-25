namespace core
{

    struct CommandBufferState
    {
        PipelineVk graphicsPipeline;
        PipelineVk computePipeline;

        char pushConstantsData[512];

        
    };

    class CommandBufferVk
    {
        public:
        CommandBufferVk(){}
        VkResult init();

        private:

    };
}