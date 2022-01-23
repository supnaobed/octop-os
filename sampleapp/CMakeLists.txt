cmake_minimum_required(VERSION 3.5)

project(sample)

find_library(libsdk libsdk.a)
find_library(libmessenger libmessenger.a)
find_library(octonet liboctonet.a)
find_library(motor libmotor.a)

message(STATUS ${libsdk})
message(STATUS ${octonet})
message(STATUS ${motor})

include_directories(/usr/local/include)

add_executable(sample application.c)

target_link_libraries(sample PRIVATE ${libmessenger} ${libsdk} ${octonet} ${motor})




