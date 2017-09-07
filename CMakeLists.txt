cmake_minimum_required (VERSION 2.8.11)
project (LoadGenerator)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -pedantic -g -ggdb -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -pedantic -O3")

if(NOT CMAKE_BUILD_TYPE) 
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")

add_executable (load_generator 
                generator.cpp 
                Results.cpp 
                Requests.cpp 
                policies.cpp)

target_link_libraries (load_generator 
                    boost_system 
                    pthread)


