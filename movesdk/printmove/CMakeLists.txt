cmake_minimum_required(VERSION 3.5)

project(printmove)

include_directories(/usr/local/include)

SET(PUBLIC_SOURCES_FILES
	"src/PrintMove.c"
)

ADD_LIBRARY (
	printmove SHARED ${PUBLIC_SOURCES_FILES} ${PRIVATE_SOURCES_FILES}
)

INSTALL (
	TARGETS printmove
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
