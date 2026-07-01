cmake_minimum_required(VERSION 3.16)

project(graph_visualizer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(
    graph_visualizer

    src/main.cpp
    src/graph.cpp
    src/algorithms.cpp
    src/visualizer.cpp
)

target_compile_options(graph_visualizer PRIVATE
    -Wall
    -Wextra
    -pedantic
)