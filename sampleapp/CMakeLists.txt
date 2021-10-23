cmake_minimum_required(VERSION 3.5)

project(sample)

find_library(libsdk libsdk.a)
find_library(libmessenger libmessenger.a)
message(STATUS ${libsdk})

include_directories(/usr/local/include)

add_executable(sample application.c)

target_link_libraries(sample
    PRIVATE 
        ${libmessenger}
)

target_link_libraries(sample
    PRIVATE 
        ${libsdk}
)




