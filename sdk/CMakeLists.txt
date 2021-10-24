cmake_minimum_required(VERSION 3.5)

project(sdk VERSION 1.0.1 DESCRIPTION "sdk")

find_library(libmessenger libmessenger.a)

include_directories(/usr/local/include)

set(PUBLIC_HEADERS
	"include/App.h"
    "include/AppDelegate.h"
)

SET(PUBLIC_SOURCES_FILES
	"src/App.c"
    "src/AppLifecycle.c"
)


ADD_LIBRARY (
	sdk STATIC ${PUBLIC_SOURCES_FILES} ${PRIVATE_SOURCES_FILES}
)

target_link_libraries(sdk
    PRIVATE 
        ${libmessenger}
)

INSTALL (
	TARGETS sdk
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

INSTALL (
    DIRECTORY ${CMAKE_SOURCE_DIR}/include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")

# install(FILES include/appdelegate.h include/app.h DESTINATION ${CMAKE_SOURCE_DIR}/include/)
