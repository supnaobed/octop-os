cmake_minimum_required(VERSION 3.5)

project(messenger VERSION 1.0.1 DESCRIPTION "messenger")

set(PUBLIC_HEADERS
	"include/Message.h"
    "include/MessageQueue.h"
    "include/Queue.h"
    "include/MessageReceiver.h"
)

SET(PUBLIC_SOURCES_FILES
    "message/Message.c"
    "queue/MessageQueue.c"
    "queue/Queue.c"
    "queue/MessageReceiver.c"
)

ADD_LIBRARY (
	messenger STATIC ${PUBLIC_HEADERS} ${PUBLIC_SOURCES_FILES} ${PRIVATE_SOURCES_FILES}
)

INSTALL (
	TARGETS messenger
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

INSTALL (
    DIRECTORY ${CMAKE_SOURCE_DIR}/include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")