cmake_minimum_required(VERSION 3.5)
project (sample)

find_library(libocto libocto.so)
find_library(liboctomov liboctomov.so)


set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

message(STATUS ${libocto})
message(STATUS ${liboctomov})

include_directories(/usr/local/include)

add_executable(sample 
    sampleapp.c
)

target_link_libraries(sample 
    PRIVATE 
        Threads::Threads
)

target_link_libraries(sample
    PRIVATE 
        ${libocto}
)


target_link_libraries(sample
    PRIVATE 
        ${liboctomov}
)