cmake_minimum_required(VERSION 3.10)
project(logger)
set(CMAKE_CXX_STANDARD 17)

add_library(logger STATIC logger.cpp)