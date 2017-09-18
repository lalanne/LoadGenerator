cmake_minimum_required(VERSION 2.8.12)

set(BINARY_NAME itst)

#link_directories(${GTEST_DIR}/lib)
#link_directories(${GMOCK_DIR}/lib)
#if(CMAKE_COMPILER_IS_GNUCXX)
#    include(CodeCoverage)
#    setup_target_for_coverage(${PROJECT_NAME}_coverage ${BINARY_NAME} coverage)
#endif()


set(SOURCES
    tests.cpp
    RequestsTests.cpp
    ../../Requests.cpp
)

add_executable(${BINARY_NAME} ${SOURCES})

include_directories(../../)

include_directories(${GTEST_DIR}/include)
include_directories(${GMOCK_DIR}/include)

target_link_libraries(${BINARY_NAME} gtest )
target_link_libraries(${BINARY_NAME} gmock)
target_link_libraries(${BINARY_NAME} gcov)
target_link_libraries(${BINARY_NAME} boost_system)


