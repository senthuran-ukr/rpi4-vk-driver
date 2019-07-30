cmake_minimum_required (VERSION 3.0)

project (rpi4-vulkan-driver)

set (EXTERNAL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/external/)
include_directories(${EXTERNAL_PATH})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(driver)
