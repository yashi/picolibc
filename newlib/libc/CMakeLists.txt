zephyr_system_include_directories(include)
target_include_directories(picolibc PUBLIC include)
add_subdirectory(ctype)
add_subdirectory(errno)
add_subdirectory(signal)
add_subdirectory(stdlib)
add_subdirectory(string)
add_subdirectory(tinystdio)

# Zephyr sets _FORTIFY_SOURCE to 2
add_subdirectory(ssp)
