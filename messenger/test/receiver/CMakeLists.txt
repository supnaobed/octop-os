cmake_minimum_required(VERSION 3.5)

project(receiver)

find_library(libmessenger libmessenger.dylib)
message(STATUS ${libmessenger})

include_directories(/usr/local/include/)

add_executable(receiver main.c)

target_link_libraries(receiver
    PRIVATE 
        ${libmessenger}
)
