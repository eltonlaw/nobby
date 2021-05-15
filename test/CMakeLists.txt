cmake_minimum_required(VERSION 3.20)
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(test_gcode_parser test_gcode_parser.cpp)
    target_link_libraries(test_gcode_parser
                          nobby
                          ${Boost_FILESYSTEM_LIBRARY}
                          ${Boost_SYSTEM_LIBRARY}
                          ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                          )
    target_include_directories(test_gcode_parser PUBLIC
                               ${PROJECT_SOURCE_DIR}/nobby
                              )
    add_test(gcode_parser test_gcode_parser)
endif()
