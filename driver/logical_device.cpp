#include <vulkan/vulkan.h>
#include <memory.h>
#include <assert.h>
#include "base.h"
#include "defines.h"
#include "log.h"
#include "logical_device.h"
#include  "vkobject.h"
#define SUPPORTED_QUEUE_FLAGS VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT

static const VkQueueFamilyProperties g_queue_family_prop[] = 
{
    {
        .queueFlags = VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT | VK_QUEUE_SPARSE_BINDING_BIT,
        .queueCount = 1,
        .timestampValidBits = 64,
        .minImageTransferGranularity = {1,1,1}
    },// Universal Queue Family
};

static const uint32_t num_queue_families = sizeof(g_queue_family_prop) / sizeof(VkQueueFamilyProperties);


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

const static VkPhysicalDeviceFeatures device_features =
{
    0, //    robustBufferAccess0,
    0, //    fullDrawIndexUint320,
    0, //    imageCubeArray0,
    0, //    independentBlend0,
    0, //    geometryShader0,
    0, //    tessellationShader0,
    0, //    sampleRateShading0,
    0, //    dualSrcBlend0,
    0, //    logicOp0,
    0, //    multiDrawIndirect0,
    0, //    drawIndirectFirstInstance0,
    0, //    depthClamp0,
    0, //    depthBiasClamp0,
    0, //    fillModeNonSolid0,
    0, //    depthBounds0,
    0, //    wideLines0,
    0, //    largePoints0,
    0, //    alphaToOne0,
    0, //    multiViewport0,
    0, //    samplerAnisotropy0,
    0, //    textureCompressionETC20,
    0, //    textureCompressionASTC_LDR0,
    0, //    textureCompressionBC0,
    0, //    occlusionQueryPrecise0,
    0, //    pipelineStatisticsQuery0,
    0, //    vertexPipelineStoresAndAtomics0,
    0, //    fragmentStoresAndAtomics0,
    0, //    shaderTessellationAndGeometryPointSize0,
    0, //    shaderImageGatherExtended0,
    0, //    shaderStorageImageExtendedFormats0,
    0, //    shaderStorageImageMultisample0,
    0, //    shaderStorageImageReadWithoutFormat0,
    0, //    shaderStorageImageWriteWithoutFormat0,
    0, //    shaderUniformBufferArrayDynamicIndexing0,
    0, //    shaderSampledImageArrayDynamicIndexing0,
    0, //    shaderStorageBufferArrayDynamicIndexing0,
    0, //    shaderStorageImageArrayDynamicIndexing0,
    0, //    shaderClipDistance0,
    0, //    shaderCullDistance0,
    0, //    shaderFloat640,
    0, //    shaderInt640,
    0, //    shaderInt160,
    0, //    shaderResourceResidency0,
    0, //    shaderResourceMinLod0,
    0, //    sparseBinding0,
    0, //    sparseResidencyBuffer0,
    0, //    sparseResidencyImage2D0,
    0, //    sparseResidencyImage3D0,
    0, //    sparseResidency2Samples0,
    0, //    sparseResidency4Samples0,
    0, //    sparseResidency8Samples0,
    0, //    sparseResidency16Samples0,
    0, //    sparseResidencyAliased0,
    0, //    variableMultisampleRate0,
    0, //    inheritedQueries0,
};

void update_device_feature(VkPhysicalDeviceFeatures* pDeviceFeature)
{
#define CHECK_AND_UPDATE_FEATURE(x) pDeviceFeature->x = pDeviceFeature->x && device_features.x

    CHECK_AND_UPDATE_FEATURE(robustBufferAccess);
    CHECK_AND_UPDATE_FEATURE(fullDrawIndexUint32);
    CHECK_AND_UPDATE_FEATURE(imageCubeArray);
    CHECK_AND_UPDATE_FEATURE(independentBlend);
    CHECK_AND_UPDATE_FEATURE(geometryShader);
    CHECK_AND_UPDATE_FEATURE(tessellationShader);
    CHECK_AND_UPDATE_FEATURE(sampleRateShading);
    CHECK_AND_UPDATE_FEATURE(dualSrcBlend);
    CHECK_AND_UPDATE_FEATURE(logicOp);
    CHECK_AND_UPDATE_FEATURE(multiDrawIndirect);
    CHECK_AND_UPDATE_FEATURE(drawIndirectFirstInstance);
    CHECK_AND_UPDATE_FEATURE(depthClamp);
    CHECK_AND_UPDATE_FEATURE(depthBiasClamp);
    CHECK_AND_UPDATE_FEATURE(fillModeNonSolid);
    CHECK_AND_UPDATE_FEATURE(depthBounds);
    CHECK_AND_UPDATE_FEATURE(wideLines);
    CHECK_AND_UPDATE_FEATURE(largePoints);
    CHECK_AND_UPDATE_FEATURE(alphaToOne);
    CHECK_AND_UPDATE_FEATURE(multiViewport);
    CHECK_AND_UPDATE_FEATURE(samplerAnisotropy);
    CHECK_AND_UPDATE_FEATURE(textureCompressionETC2);
    CHECK_AND_UPDATE_FEATURE(textureCompressionASTC_LDR);
    CHECK_AND_UPDATE_FEATURE(textureCompressionBC);
    CHECK_AND_UPDATE_FEATURE(occlusionQueryPrecise);
    CHECK_AND_UPDATE_FEATURE(pipelineStatisticsQuery);
    CHECK_AND_UPDATE_FEATURE(vertexPipelineStoresAndAtomics);
    CHECK_AND_UPDATE_FEATURE(fragmentStoresAndAtomics);
    CHECK_AND_UPDATE_FEATURE(shaderTessellationAndGeometryPointSize);
    CHECK_AND_UPDATE_FEATURE(shaderImageGatherExtended);
    CHECK_AND_UPDATE_FEATURE(shaderStorageImageExtendedFormats);
    CHECK_AND_UPDATE_FEATURE(shaderStorageImageMultisample);
    CHECK_AND_UPDATE_FEATURE(shaderStorageImageReadWithoutFormat);
    CHECK_AND_UPDATE_FEATURE(shaderStorageImageWriteWithoutFormat);
    CHECK_AND_UPDATE_FEATURE(shaderUniformBufferArrayDynamicIndexing);
    CHECK_AND_UPDATE_FEATURE(shaderSampledImageArrayDynamicIndexing);
    CHECK_AND_UPDATE_FEATURE(shaderStorageBufferArrayDynamicIndexing);
    CHECK_AND_UPDATE_FEATURE(shaderStorageImageArrayDynamicIndexing);
    CHECK_AND_UPDATE_FEATURE(shaderClipDistance);
    CHECK_AND_UPDATE_FEATURE(shaderCullDistance);
    CHECK_AND_UPDATE_FEATURE(shaderFloat64);
    CHECK_AND_UPDATE_FEATURE(shaderInt64);
    CHECK_AND_UPDATE_FEATURE(shaderInt16);
    CHECK_AND_UPDATE_FEATURE(shaderResourceResidency);
    CHECK_AND_UPDATE_FEATURE(shaderResourceMinLod);
    CHECK_AND_UPDATE_FEATURE(sparseBinding);
    CHECK_AND_UPDATE_FEATURE(sparseResidencyBuffer);
    CHECK_AND_UPDATE_FEATURE(sparseResidencyImage2D);
    CHECK_AND_UPDATE_FEATURE(sparseResidencyImage3D);
    CHECK_AND_UPDATE_FEATURE(sparseResidency2Samples);
    CHECK_AND_UPDATE_FEATURE(sparseResidency4Samples);
    CHECK_AND_UPDATE_FEATURE(sparseResidency8Samples);
    CHECK_AND_UPDATE_FEATURE(sparseResidency16Samples);
    CHECK_AND_UPDATE_FEATURE(sparseResidencyAliased);
    CHECK_AND_UPDATE_FEATURE(variableMultisampleRate);
    CHECK_AND_UPDATE_FEATURE(inheritedQueries);

 #undef CHECK_AND_UPDATE_FEATURE
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



VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties*                 pProperties);

VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties*                    pQueueFamilyProperties)
{

    core::DispatchableObjectPhysicalDevice::cast(physicalDevice)->getQueueFamilyProperties();
}

VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties*           pMemoryProperties);

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetInstanceProcAddr(
    VkInstance                                  instance,
    const char*                                 pName);

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetDeviceProcAddr(
    VkDevice                                    device,
    const char*                                 pName);

namespace core{
VkResult LogicalDeviceVk::getQueue(uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue)const
{
    auto it = mQueues.find(queueFamilyIndex);
    if(it == mQueues.end())
        return VK_INCOMPLETE;
    if(it->second.size() <= queueIndex)
        return VK_INCOMPLETE;
    *pQueue = DispatchableObjectQueue::cast(it->second[queueIndex]);
    return VK_SUCCESS;
}


}
VKAPI_ATTR void VKAPI_CALL vkDestroyDevice(
    VkDevice                                    device,
    const VkAllocationCallbacks*                pAllocator)
{
    UNUSED_VARIABLE(pAllocator);
    assert(device);
    Vk_Device* _device = device;
    FREE(_device);
}


VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceQueue(VkDevice  device,
    uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue)
{
    ASSERT(device, "Device must not be NULL");
    ASSERT(pQueue != NULL, "pQueue must not be NULL");

    return core::DispatchableObjectLogicalDevice::cast(device)->getQueue(queueFamilyIndex, queueIndex, pQueue);
}

VKAPI_ATTR VkResult VKAPI_CALL vkCreateGraphicsPipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkGraphicsPipelineCreateInfo*         pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines)
{
    ASSERT(device, "Device must not be NULL");
    return core::DispatchableObjectLogicalDevice::cast(device)->createGraphicsPipeline(pipelineCache, createInfoCount, 
        pCreateInfos, pAllocator, pPipelines);
}




