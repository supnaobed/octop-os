cmake_minimum_required(VERSION 3.5)
project (sample)

find_library(libocto libocto.dylib)
find_library(liboctomov liboctomov.dylib)
message(STATUS ${libocto})
message(STATUS ${liboctomov})

include_directories(/usr/local/include)

add_executable(sample 
    sampleapp.c
)

target_link_libraries(sample
    PRIVATE 
        ${libocto}
)


target_link_libraries(sample
    PRIVATE 
        ${liboctomov}
)