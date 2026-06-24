cmake_minimum_required(VERSION 3.14)
project(stl-lite)

if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(./include)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)


# --- Vector Tests ---
add_executable(test_vector tests/test_vector.cpp)
target_link_libraries(test_vector gtest_main)
set_target_properties(test_vector PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
gtest_discover_tests(test_vector)

# --- Stack Tests ---
add_executable(test_stack tests/test_stack.cpp)
target_link_libraries(test_stack gtest_main)
set_target_properties(test_stack PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
gtest_discover_tests(test_stack)

# --- Queue Tests ---
add_executable(test_queue tests/test_queue.cpp)
target_link_libraries(test_queue gtest_main)
set_target_properties(test_queue PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
gtest_discover_tests(test_queue)