cmake_minimum_required(VERSION 2.8.12)

set(BINARY_NAME utst)

set(GTEST_DIR "/usr/include/gtest" CACHE STRING "Options: [$ENV{HOME}/gtest")
set(GMOCK_DIR "/usr/include/gmock" CACHE STRING "Options: [$ENV{HOME}/gmock")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -pthread -g -O0 -fprofile-arcs -ftest-coverage")
#link_directories(${GTEST_DIR}/lib)
#link_directories(${GMOCK_DIR}/lib)
if(CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    setup_target_for_coverage(${PROJECT_NAME}_coverage ${BINARY_NAME} coverage)
endif()


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
target_link_libraries(${BINARY_NAME} gcov)

add_test(NAME example_test COMMAND ./utst)

include(CTest)
enable_testing()

