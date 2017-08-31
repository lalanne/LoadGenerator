cmake_minimum_required (VERSION 2.8.11)
project (LoadGenerator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")
add_executable (load_generator 
                generator.cpp 
                Results.cpp 
                Requests.cpp 
                policies.cpp)

target_link_libraries (load_generator 
                    boost_system 
                    pthread)


