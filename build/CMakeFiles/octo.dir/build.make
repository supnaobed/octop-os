# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.20.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.20.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ishmukhametov/Developer/octop-os

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ishmukhametov/Developer/octop-os/build

# Include any dependencies generated for this target.
include CMakeFiles/octo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/octo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/octo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/octo.dir/flags.make

CMakeFiles/octo.dir/src/sdk/app.c.o: CMakeFiles/octo.dir/flags.make
CMakeFiles/octo.dir/src/sdk/app.c.o: ../src/sdk/app.c
CMakeFiles/octo.dir/src/sdk/app.c.o: CMakeFiles/octo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ishmukhametov/Developer/octop-os/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/octo.dir/src/sdk/app.c.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/octo.dir/src/sdk/app.c.o -MF CMakeFiles/octo.dir/src/sdk/app.c.o.d -o CMakeFiles/octo.dir/src/sdk/app.c.o -c /Users/ishmukhametov/Developer/octop-os/src/sdk/app.c

CMakeFiles/octo.dir/src/sdk/app.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/octo.dir/src/sdk/app.c.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ishmukhametov/Developer/octop-os/src/sdk/app.c > CMakeFiles/octo.dir/src/sdk/app.c.i

CMakeFiles/octo.dir/src/sdk/app.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/octo.dir/src/sdk/app.c.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ishmukhametov/Developer/octop-os/src/sdk/app.c -o CMakeFiles/octo.dir/src/sdk/app.c.s

CMakeFiles/octo.dir/src/sdk/sampleapp.c.o: CMakeFiles/octo.dir/flags.make
CMakeFiles/octo.dir/src/sdk/sampleapp.c.o: ../src/sdk/sampleapp.c
CMakeFiles/octo.dir/src/sdk/sampleapp.c.o: CMakeFiles/octo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ishmukhametov/Developer/octop-os/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/octo.dir/src/sdk/sampleapp.c.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/octo.dir/src/sdk/sampleapp.c.o -MF CMakeFiles/octo.dir/src/sdk/sampleapp.c.o.d -o CMakeFiles/octo.dir/src/sdk/sampleapp.c.o -c /Users/ishmukhametov/Developer/octop-os/src/sdk/sampleapp.c

CMakeFiles/octo.dir/src/sdk/sampleapp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/octo.dir/src/sdk/sampleapp.c.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ishmukhametov/Developer/octop-os/src/sdk/sampleapp.c > CMakeFiles/octo.dir/src/sdk/sampleapp.c.i

CMakeFiles/octo.dir/src/sdk/sampleapp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/octo.dir/src/sdk/sampleapp.c.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ishmukhametov/Developer/octop-os/src/sdk/sampleapp.c -o CMakeFiles/octo.dir/src/sdk/sampleapp.c.s

CMakeFiles/octo.dir/src/sdk/robmov.c.o: CMakeFiles/octo.dir/flags.make
CMakeFiles/octo.dir/src/sdk/robmov.c.o: ../src/sdk/robmov.c
CMakeFiles/octo.dir/src/sdk/robmov.c.o: CMakeFiles/octo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ishmukhametov/Developer/octop-os/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/octo.dir/src/sdk/robmov.c.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/octo.dir/src/sdk/robmov.c.o -MF CMakeFiles/octo.dir/src/sdk/robmov.c.o.d -o CMakeFiles/octo.dir/src/sdk/robmov.c.o -c /Users/ishmukhametov/Developer/octop-os/src/sdk/robmov.c

CMakeFiles/octo.dir/src/sdk/robmov.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/octo.dir/src/sdk/robmov.c.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ishmukhametov/Developer/octop-os/src/sdk/robmov.c > CMakeFiles/octo.dir/src/sdk/robmov.c.i

CMakeFiles/octo.dir/src/sdk/robmov.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/octo.dir/src/sdk/robmov.c.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ishmukhametov/Developer/octop-os/src/sdk/robmov.c -o CMakeFiles/octo.dir/src/sdk/robmov.c.s

# Object files for target octo
octo_OBJECTS = \
"CMakeFiles/octo.dir/src/sdk/app.c.o" \
"CMakeFiles/octo.dir/src/sdk/sampleapp.c.o" \
"CMakeFiles/octo.dir/src/sdk/robmov.c.o"

# External object files for target octo
octo_EXTERNAL_OBJECTS =

octo: CMakeFiles/octo.dir/src/sdk/app.c.o
octo: CMakeFiles/octo.dir/src/sdk/sampleapp.c.o
octo: CMakeFiles/octo.dir/src/sdk/robmov.c.o
octo: CMakeFiles/octo.dir/build.make
octo: CMakeFiles/octo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ishmukhametov/Developer/octop-os/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable octo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/octo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/octo.dir/build: octo
.PHONY : CMakeFiles/octo.dir/build

CMakeFiles/octo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/octo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/octo.dir/clean

CMakeFiles/octo.dir/depend:
	cd /Users/ishmukhametov/Developer/octop-os/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ishmukhametov/Developer/octop-os /Users/ishmukhametov/Developer/octop-os /Users/ishmukhametov/Developer/octop-os/build /Users/ishmukhametov/Developer/octop-os/build /Users/ishmukhametov/Developer/octop-os/build/CMakeFiles/octo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/octo.dir/depend

