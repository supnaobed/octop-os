cmake_minimum_required(VERSION 3.5)

project (sample)

set(SOURCES
    src/app.c
    src/sampleapp.c
    src/robmov.c
)

add_executable(sample ${SOURCES})
