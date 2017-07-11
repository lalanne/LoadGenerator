cmake_minimum_required (VERSION 2.8.11)
project (LoadGenerator)

#add_subdirectory (Hello)
#add_subdirectory (Demo)

#target_include_directories (Hello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_executable (load_generator generator.cpp)
target_link_libraries (load_generator boost_system)


