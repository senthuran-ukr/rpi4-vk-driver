#include <vulkan/vulkan.h>
#include "defines.h"
#include "string.h"
#include  "version.h"
#include <map>
namespace core{


constexpr uint32_t API_VERSION = VK_API_VERSION_1_0;
constexpr uint32_t DRIVER_VERSION = VK_MAKE_VERSION(MAJOR_VERSION, MINOR_VESION, PATCH_VERSION);

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

namespace Limits
{
  constexpr uint32_t MAX_BOUND_DESCRIPTOR_SETS = 16;
  constexpr uint32_t MAX_VIEWPORTS = 16;

  constexpr uint32_t MAX_IMAGE_LEVELS_1D = 15;
  constexpr uint32_t MAX_IMAGE_LEVELS_2D = 15;
  constexpr uint32_t MAX_IMAGE_LEVELS_3D = 12;
  constexpr uint32_t MAX_IMAGE_LEVELS_CUBE = 15;
  constexpr uint32_t MAX_IMAGE_ARRAY_LAYERS = 1024;
  constexpr uint32_t MAX_PHYSICAL_DEVICE = 1;

  constexpr uint32_t MAX_PHYSICAL_DEVICES = 1;
  constexpr uint32_t NUM_DEVICE_QUEUE_SUPPORTED = 1;
  constexpr uint32_t MAX_DEVICE_QUEUE_FAMILY_SUPPORTED  = 1;

  struct QueueFamily
  {
    uint32_t numQueueSupported;
    bool supportPresentation;
  };

  std::map<uint32_t, QueueFamily> queueFamily = {{VK_QUEUE_COMPUTE_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_TRANSFER_BIT}, QueueFamily{1u, true}};
}
}