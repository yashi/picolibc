project(PICOLIBC)
cmake_minimum_required(VERSION 3.20)

add_library(picolibc)
#target_compile_features(picolibc PRIVATE c_std_18)
target_compile_options(picolibc PRIVATE -Wall -Wextra)

set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Debug Release MinSizeRel)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "No build type selected, default to MinSizeRel")
  set(CMAKE_BUILD_TYPE MinSizeRel CACHE STRING "Build Type" FORCE)
endif()

target_include_directories(picolibc INTERFACE ${CMAKE_CURRENT_BINARY_DIR})
target_compile_options(picolibc PUBLIC -include ${CMAKE_CURRENT_BINARY_DIR}/picolibc.h)
zephyr_system_include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(newlib)

configure_file(picolibc.h.in picolibc.h)

target_link_options(picolibc PUBLIC -Wl,--defsym=vfprintf=__d_vfprintf)
