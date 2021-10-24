cmake_minimum_required(VERSION 3.5)

project(sender)

find_library(libmessenger libmessenger.a)
message(STATUS ${libmessenger})

include_directories(/usr/local/include/)

add_executable(sender main.c)

target_link_libraries(sender
    PRIVATE 
        ${libmessenger}
)
