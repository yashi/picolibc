zephyr_system_include_directories(.)
target_include_directories(picolibc PUBLIC .)
target_sources(picolibc PRIVATE
  dtoa_data.c
  dtoa_engine.c
  filestrput.c
  fputc.c
  printf.c
  snprintf.c
  vfprintf.c
  vprintf.c
  )
