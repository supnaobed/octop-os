cmake_minimum_required(VERSION 3.5)

project (octo)

set(SOURCES
    src/sdk/app.c
    src/sdk/sampleapp.c
    src/sdk/robmov.c
)

add_executable(octo ${SOURCES})
