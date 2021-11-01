cmake_minimum_required(VERSION 3.5)

project(launcher)
find_library(libmessenger libmessenger.a)
include_directories(/usr/local/include)

set(PUBLIC_HEADERS
	"include/cmd.h"
    "include/proc.h"
    "include/util.h"
    "include/sender.h"
)

add_executable(launcher 
    src/cmdin.c
    src/launcher.c
    src/proc.c
    src/util.c
    src/sender.c
)

target_link_libraries(launcher
    PRIVATE 
        ${libmessenger}
)