cmake_minimum_required(VERSION 3.6.0)

# enable ctest so `make test` runs unit tests
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT nobby)
project(${PROJECT} VERSION 0.1.0 LANGUAGES CXX)

configure_file(config.h.in config.h)
set(CONFIG_INCLUDE ${PROJECT_BINARY_DIR})

add_subdirectory(${PROJECT})
add_subdirectory(test)

