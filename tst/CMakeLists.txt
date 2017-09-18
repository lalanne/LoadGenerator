cmake_minimum_required(VERSION 2.8.12)


set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -g -O0 -fprofile-arcs -ftest-coverage")


set(GTEST_DIR "/usr/include/gtest" CACHE STRING "Options: [$ENV{HOME}/gtest")
set(GMOCK_DIR "/usr/include/gmock" CACHE STRING "Options: [$ENV{HOME}/gmock")

include_directories(../)

include_directories(${GTEST_DIR}/include)
include_directories(${GMOCK_DIR}/include)

add_subdirectory(utst)
add_subdirectory(itst)


