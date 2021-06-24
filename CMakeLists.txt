cmake_minimum_required(VERSION 3.5)

project (octo)

set(SOURCES
    src/app.c
    src/sampleapp.c
    src/robmov.c
)

add_executable(octo ${SOURCES})
