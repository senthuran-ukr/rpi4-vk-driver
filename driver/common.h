#pragma once


typedef struct VK_Instance;
#define MAX_PHYSICAL_DEVICES 1

typedef struct
{
    VK_Instance* instance;
}VK_PhysicalDevice;


typedef struct
{
    VK_PhysicalDevice devices[MAX_PHYSICAL_DEVICES];



}VK_Instance;


#undef MAX_PHYSICAL_DEVICES
