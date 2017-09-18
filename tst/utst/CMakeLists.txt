cmake_minimum_required(VERSION 2.8.12)

set(BINARY_NAME_UTST utst)

if(CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    setup_target_for_coverage(${PROJECT_NAME}_coverage1 ${BINARY_NAME_UTST} coverage)
endif()



set(SOURCES_UTST
    tests.cpp
    ArgumentsTests.cpp
    ResultsTests.cpp
    ../../Results.cpp
    ../../Requests.cpp
    ../../policies.cpp
)

add_executable(${BINARY_NAME_UTST} ${SOURCES_UTST})

target_link_libraries(${BINARY_NAME_UTST} gtest )
target_link_libraries(${BINARY_NAME_UTST} gmock)
target_link_libraries(${BINARY_NAME_UTST} gcov)
target_link_libraries(${BINARY_NAME_UTST} boost_system)


