cmake_minimum_required(VERSION 2.8.12)

set(BINARY_NAME utst)

set(GTEST_DIR "/usr/include/gtest" CACHE STRING "Options: [$ENV{HOME}/gtest")
set(GMOCK_DIR "/usr/include/gmock" CACHE STRING "Options: [$ENV{HOME}/gmock")

set (CMAKE_CXX_STANDARD 11)
#link_directories(${GTEST_DIR}/lib)
#link_directories(${GMOCK_DIR}/lib)

set(SOURCES
    tests.cpp
    ArgumentsTests.cpp
    ResultsTests.cpp
    ../Results.cpp
)

add_executable(${BINARY_NAME} ${SOURCES})

include_directories(../)

include_directories(${GTEST_DIR}/include)
include_directories(${GMOCK_DIR}/include)

target_link_libraries(${BINARY_NAME} gtest )
target_link_libraries(${BINARY_NAME} gmock)
