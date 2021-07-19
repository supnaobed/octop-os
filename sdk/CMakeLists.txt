cmake_minimum_required(VERSION 3.9)

project(octo VERSION 1.0.1 DESCRIPTION "sdk")

add_library(octo SHARED src/app.c src/robmov.c)

set(PUBLIC_HEADERS
    include/static/app.h
    include/static/robmov.h
)

set_target_properties(octo PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER "${PUBLIC_HEADERS}")

target_include_directories(octo PRIVATE .)

install(TARGETS octo
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

INSTALL (
    DIRECTORY ${CMAKE_SOURCE_DIR}/include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")