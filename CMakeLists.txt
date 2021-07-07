cmake_minimum_required(VERSION 3.5)

project (octo)

set(SOURCES
    src/sdk/app.c
    src/sdk/sampleapp.c
    src/sdk/robmov.c
    src/installer/client/libinstall.c
    src/installer/client/libinstall.h
    src/installer/client/utils.c
    src/installer/client/utils.h
    src/installer/client/unpack.c
    src/installer/client/unpack.h
)

add_executable(octo ${SOURCES})
