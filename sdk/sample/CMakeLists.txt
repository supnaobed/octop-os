cmake_minimum_required(VERSION 3.5)
project (sample)

find_library(libhello libhello.dylib)
message(STATUS ${libhello})

include_directories(/usr/local/include)

add_executable(hello_binary 
    sampleapp.c
)


# link the new hello_library target with the hello_binary target
target_link_libraries( hello_binary
    PRIVATE 
        ${libhello}
)
