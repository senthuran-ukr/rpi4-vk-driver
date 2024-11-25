#pragma once
#include <vulkan/vulkan.h>
#include <memory>
namespace core
{
    template<typename T, typename VkType, typename CreateInfo, typename... Args>
    VkResult create(const VkAllocationCallbacks *pAllocator, const CreateInfo* pCreateInfo, VkType* pOutObject, Args... args)
    {
        *pOutObject = VK_NULL_HANDLE;
        // allocate
        T* vkObject = new T();
        if(!vkObject)
        {
            return VK_ERROR_OUT_OF_HOST_MEMORY;
        }
        VkResult result = vkObject->init(pCreateInfo, args);
        if(result)
            delete vkObject;
        else
            *pOutObject = vkObject;
        return  result;
    }

    template<typename VkType, typename T>
    class DispatchableObject
    {
        public:
        template<typename... Args>
        DispatchableObject(Args... args) : object(args...){}
        ~DispatchableObject() = delete;
        void destroy(const VkAllocationCallbacks* pAllocator)
        {
            object.destroy(pAlloator);
        }

        template<typename CreateInfo, typename... Args>
        static VkResult create(const VkAllocationCallbacks* pAllocator, const CreateInfo* pCreateInfo, VkType* pOutObj, Args... args)
        {
            return core::create<DispatchableObject<VkType, T>, VkType, CreateInfo>(pAllocator, pCreateInfo, pOutObj, args...);
        }

        static T* cast(VkType vkObject)
        {
            if(vkObject == VK_NULL_HANDLE)
                return nullptr;
            return &(reinterpret_cast<DispatchableObject<VkType, T>*>(vkObject)->object);
        }
        
        VkType cast(T* t)
        {
            return (VkType)t;
        }

        private:
        typedef DispatchableObject<VkType, T> DispatchableObjectType; 
        T object;
    };


    // Dispatchable object
    class InstanceVk;
    class PhysicalDeviceVk;
    class LogicalDeviceVk;
    class QueueVk;

    typedef DispatchableObject<VkInstance, InstanceVk> DispatchableObjectInstance;
    typedef DispatchableObject<VkPhysicalDevice, PhysicalDeviceVk> DispatchableObjectPhysicalDevice;
    typedef DispatchableObject<VkDevice, LogicalDeviceVk> DispatchableObjectLogicalDevice;
    typedef DispatchableObject<VkQueue, QueueVk> DispatchableObjectQueue;
}