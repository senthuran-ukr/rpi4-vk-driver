#include <vulkan/vulkan.h>
#include "defines.h"
#include "string.h"



static VkExtensionProperties instance_extensions[] =
{
    { "VK_KHR_surface", 25 },
    { "VK_KHR_display", 21 },
    { "VK_EXT_direct_mode_display", 1},
};
#define NUM_INSTANCE_EXTENSIONS ARRAY_SIZE(instance_extensions, VkExtensionProperties)



const static VkExtensionProperties device_extensions[] =
{
  { "VK_KHR_display_swapchain", 9 },
  { "VK_KHR_swapchain", 70 },
  { "VK_KHR_driver_properties", 1 },
};
#define NUM_DEVICE_EXTENSIONS ARRAY_SIZE(device_extensions, VkExtensionProperties)


const static VkLayerProperties device_layers[] =
{
    // layerName, specVersion,implementationVersion, description
    //{"", },
};








