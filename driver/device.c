#include <vulkan/vulkan.h>
#include "base.h"
#include "defines.h"
#include <assert.h>
#include <memory.h>



/*!
 * \brief Returns the spec version number if the device extension is supported, else return -1
 * \param extension
 * \return extension spec version number
 */
int32_t is_device_extension_supported(const char* extension)
{
    for(uint32_t i = 0; i < NUM_DEVICE_EXTENSIONS; ++i)
    {
        if(strcmp(device_extensions[i].extensionName, extension) == 0)
            return i;
    }
    return -1;
}

/*!
 * \brief Returns the spec version number if the instance extension is supported, else return -1
 * \param extension
 * \return extension spec version number
 */
int32_t is_instance_extension_supported(const char* extension)
{
    for(uint32_t i = 0; i < NUM_INSTANCE_EXTENSIONS; ++i)
    {
        if(strcmp(instance_extensions[i].extensionName, extension) == 0)
            return i;
    }
    return -1;
}

int32_t is_layer_supported(const char* layer)
{
    return -1;
}



VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDevices(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceCount,
    VkPhysicalDevice*                           pPhysicalDevices)
{
    assert(instance);
    assert(pPhysicalDeviceCount);

    uint32_t num_gpus = 1;
    if(pPhysicalDevices == NULL)
    {
        *pPhysicalDeviceCount = num_gpus;
        return VK_SUCCESS;
    }

    for(uint32_t i = 0; i < num_gpus; ++i)
    {
        pPhysicalDevices[i] = &instance->devices[i];
    }
    *pPhysicalDeviceCount = num_gpus;
    return VK_SUCCESS;
}

VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFeatures(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures*                   pFeatures)
{
    //@TODO
}

VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties*                         pFormatProperties);

VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceImageFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkImageFormatProperties*                    pImageFormatProperties);

VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties*                 pProperties);

VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties*                    pQueueFamilyProperties);

VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties*           pMemoryProperties);

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetInstanceProcAddr(
    VkInstance                                  instance,
    const char*                                 pName);

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetDeviceProcAddr(
    VkDevice                                    device,
    const char*                                 pName);

VKAPI_ATTR VkResult VKAPI_CALL vkCreateDevice(
    VkPhysicalDevice                            physicalDevice,
    const VkDeviceCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDevice*                                   pDevice)
{
    UNUSED_VARIABLE(pAllocator);

    assert(physicalDevice);
    assert(pCreateInfo);
    assert(pDevice);

    *pDevice = ALLOC(sizeof(Vk_Device), 1, VK_SYSTEM_ALLOCATION_SCOPE_DEVICE);

    if(!*pDevice)
        return VK_ERROR_OUT_OF_HOST_MEMORY;
    memset(*pDevice, 0, sizeof(Vk_Device));

    ((Vk_Device*)(*pDevice))->pPhysicalDevice = physicalDevice;

    Vk_Device* _pDevice =  (Vk_Device*)*pDevice;


    // Process supported extensions
    for(uint32_t i = 0; i < pCreateInfo->enabledExtensionCount; ++i)
    {
        int32_t extension_id = -1;
        if((extension_id = is_device_extension_supported(pCreateInfo->ppEnabledExtensionNames[i])) != -1)
        {
            _pDevice->enabled_extensions[i] = extension_id;
            ++_pDevice->num_enabled_extensions;
        }
        else {
            LOG_DEBUG("Requested extension %s not supported",
                      pCreateInfo->ppEnabledExtensionNames[i]);
        }
    }

    // @TODO Process supported Layers


















    return VK_SUCCESS;

}

VKAPI_ATTR void VKAPI_CALL vkDestroyDevice(
    VkDevice                                    device,
    const VkAllocationCallbacks*                pAllocator);



