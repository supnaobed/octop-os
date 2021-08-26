cmake_minimum_required(VERSION 3.9)

project(octomov VERSION 1.0.1 DESCRIPTION "robmov")

add_library(octomov SHARED 
src/robmov.c  
src/robmov1.cpp
src/iarduino_I2C_Motor.cpp
)

set(PUBLIC_HEADERS
    include/static/robmov1.h
    include/static/robmov.h
)

set_target_properties(octomov PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER "${PUBLIC_HEADERS}")

target_include_directories(octomov PRIVATE .)

install(TARGETS octomov
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

INSTALL (
    DIRECTORY ${CMAKE_SOURCE_DIR}/include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")
