cmake_minimum_required(VERSION 3.5)
project (sample)

find_library(libocto libocto.dylib)
message(STATUS ${libocto})

include_directories(/usr/local/include)

add_executable(sample 
    sampleapp.c
)

target_link_libraries(sample
    PRIVATE 
        ${libocto}
)
