cmake_minimum_required(VERSION 3.5)

project(move)

set(PUBLIC_HEADERS
	"include/Move.h"
)

INSTALL (
    DIRECTORY ${CMAKE_SOURCE_DIR}/include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")