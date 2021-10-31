cmake_minimum_required(VERSION 3.5)

project(launcher)

set(PUBLIC_HEADERS
	"include/cmd.h"
    "include/proc.h"
    "include/util.h"
)

add_executable(launcher 
    cmdin.c
    launcher.c
    proc.c
    util.c
)
