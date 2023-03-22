
cmake_minimum_required(VERSION 3.1)
project(net_program C CXX)

set(CMAKE_C_STANDARD 99)

include_directories(${PROJECT_SOURCE_DIR})



add_subdirectory(server/)
add_subdirectory(src/)