cmake_minimum_required (VERSION 2.8)

# build modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/build/")


# dependencies
find_package(LinuxHeaders REQUIRED)
find_package(DRM REQUIRED)

include_directories(${KERNELHEADERS_INCLUDE_DIRS})

# workaround because cmake ignores include paths
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${DRM_INCLUDE_DIRS}")


# project name
set(PROJECT_NAME "vwm")
project("${PROJECT_NAME}")


# include src
include_directories("${PROJECT_SOURCE_DIR}/")


#build
add_subdirectory(src)
