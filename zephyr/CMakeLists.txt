if(CONFIG_PICOLIBC)
  set(CMAKE_SYSTEM_NAME "Zephyr")
  set(CMAKE_BUILD_TYPE None)
  set(CMAKE_C_COMPILE_FEATURES c_std_18)

  add_subdirectory(.. build)

  # Zephyr compiler options
  # target_include_directories(picolibc PRIVATE
  #   $<TARGET_PROPERTY:zephyr_interface,INTERFACE_INCLUDE_DIRECTORIES>
  #   )

  # zephyr_system_include_directories(../newlib/libc/include)

  # target_include_directories(picolibc INTERFACE
  #   $<TARGET_PROPERTY:zephyr_interface,INTERFACE_INCLUDE_DIRECTORIES>
  #   )

  # target_compile_definitions(picolibc INTERFACE
  #   $<TARGET_PROPERTY:zephyr_interface,INTERFACE_COMPILE_DEFINITIONS>
  #   )

  # target_compile_options(picolibc INTERFACE
  #   $<TARGET_PROPERTY:zephyr_interface,INTERFACE_COMPILE_OPTIONS>
  #   -fno-builtin -Wno-shadow -Wno-cast-align
  #  )

  add_dependencies(picolibc ${SYSCALL_LIST_H_TARGET})
  zephyr_append_cmake_library(picolibc)
  target_link_libraries(picolibc PUBLIC zephyr_interface)

  target_sources(picolibc PRIVATE libc-hooks.c)

endif()
