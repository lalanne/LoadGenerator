cmake_minimum_required(VERSION 2.8.12)

set(BINARY_NAME_ITST itst)

#if(CMAKE_COMPILER_IS_GNUCXX)
#    include(CodeCoverage)
#    setup_target_for_coverage(${PROJECT_NAME}_coverage ${BINARY_NAME} coverage)
#endif()


set(SOURCES_ITST
    tests.cpp
    RequestsTests.cpp
    ../../Requests.cpp
)

add_executable(${BINARY_NAME_ITST} ${SOURCES_ITST})

target_link_libraries(${BINARY_NAME_ITST} gtest )
target_link_libraries(${BINARY_NAME_ITST} gmock)
#target_link_libraries(${BINARY_NAME_ITST} gcov)
target_link_libraries(${BINARY_NAME_ITST} boost_system)
