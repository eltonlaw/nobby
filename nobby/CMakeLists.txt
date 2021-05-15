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

target_link_libraries(${PROJECT} ${LIBS})
