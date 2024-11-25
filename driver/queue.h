#pragma once
namespace core
{
class FenceVk;
class LogicalDeviceVk;
class QueueVk
{
    public:
    QueueVk(){}
    VkResult submit(uint32_t submitCount, VkSubmitInfo* pSubmitInfos, FenceVk* fence);
    VkResult waitIdle();
    private:
    LogicalDeviceVk* mDevice = nullptr;
};
}
