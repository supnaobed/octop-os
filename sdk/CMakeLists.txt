cmake_minimum_required(VERSION 3.9)

project(hello VERSION 1.0.1 DESCRIPTION "mylib description")

add_library(hello SHARED src/hello.c)
set_target_properties(hello PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER include/hello.h)

target_include_directories(hello PRIVATE .)
install(TARGETS hello
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
INSTALL (
    DIRECTORY ${CMAKE_SOURCE_DIR}/include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")