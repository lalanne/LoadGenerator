cmake_minimum_required(VERSION 2.8.12)

set(BINARY_NAME utst)

#link_directories(${GTEST_DIR}/lib)
#link_directories(${GMOCK_DIR}/lib)
#if(CMAKE_COMPILER_IS_GNUCXX)
#    include(CodeCoverage)
#    setup_target_for_coverage(${PROJECT_NAME}_coverage ${BINARY_NAME} coverage)
#endif()


set(SOURCES
    tests.cpp
    ArgumentsTests.cpp
    ResultsTests.cpp
    ../../Results.cpp
    ../../Requests.cpp
    ../../policies.cpp
)

add_executable(${BINARY_NAME} ${SOURCES})

target_link_libraries(${BINARY_NAME} gtest )
target_link_libraries(${BINARY_NAME} gmock)
target_link_libraries(${BINARY_NAME} gcov)
target_link_libraries(${BINARY_NAME} boost_system)


