add_executable(dirty_benchmark
    benchmark_main.cpp
)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE ON)

target_include_directories(dirty_benchmark
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(dirty_benchmark
    gtest_main
    benchmark::benchmark
)