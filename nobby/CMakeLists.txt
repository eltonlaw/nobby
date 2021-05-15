if(NOT DEFINED SOURCES)
    file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
    list(FILTER SOURCES EXCLUDE REGEX ".*/main.cpp$")
endif()
if(NOT DEFINED HEADERS)
    file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*/*.h*)
endif()

set(LIBS
    pthread
    )

add_library(${PROJECT} ${SOURCES} ${HEADERS})

add_executable(nobbyd main.cpp)

target_include_directories(nobbyd PUBLIC
    ${CONFIG_INCLUDE}
    )
target_link_libraries(nobbyd
    ${PROJECT}
    )
