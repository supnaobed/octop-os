cmake_minimum_required(VERSION 3.20)

project(motor)

SET(PUBLIC_HEADERS
	"include/Motor.h"
	"include/Platform.h"
	"include/Smbus.h"
)

SET(PRIVATE_SOURCES_FILES
    "src/Motor.c"
	"src/Platform.c"
	"src/Smbus.c"
)

ADD_LIBRARY (
	motor STATIC ${PUBLIC_HEADERS} ${PUBLIC_SOURCES_FILES} ${PRIVATE_SOURCES_FILES}
)

INSTALL (
	TARGETS motor
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

INSTALL (
    DIRECTORY ${CMAKE_SOURCE_DIR}/include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")
	
