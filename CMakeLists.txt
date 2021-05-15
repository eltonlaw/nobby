cmake_minimum_required(VERSION 3.6.0)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT nobby)
project(${PROJECT} VERSION 0.1.0 LANGUAGES CXX)

add_subdirectory(nobby)
add_subdirectory(test)

