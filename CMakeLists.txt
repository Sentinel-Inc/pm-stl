cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(pm_stl)

#add_subdirectory(src)
#include_directories(src)
#link_libraries(compression_algorithms)
add_subdirectory(clock)
add_subdirectory(coord)


include_directories(clock)
include_directories(coord)

#target_add_directories(pm_stl clock)

link_libraries(performance coord)

add_library(pm_stl pm_include.h
        # Dependencies
        )
add_executable(test test.cpp)

