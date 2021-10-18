cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(pm_stl)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

#add_subdirectory(src)
#include_directories(src)
#link_libraries(compression_algorithms)
add_subdirectory(clock)
add_subdirectory(coord)


include_directories(PUBLIC clock)
include_directories(PUBLIC  coord)

#target_add_directories(pm_stl clock)


add_library(pm_stl STATIC pm_include.h  )# Dependencies )
set_target_properties( pm_stl PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(pm_stl performance coord)

add_executable(test test.cpp)

target_link_libraries(test performance coord)