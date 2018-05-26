cmake_minimum_required (VERSION 3.10)

project(stdx)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("../include")
add_executable(test_string test_string.cpp)
add_executable(test_filesystem test_filesystem.cpp)

