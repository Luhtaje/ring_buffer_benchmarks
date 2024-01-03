cmake_minimum_required(VERSION 3.22)
project(dirty_tests)

set(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(tests)
add_subdirectory(external/googletest)
add_subdirectory(external/benchmark)