# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/artem/programming/c/lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/artem/programming/c/lab3/build

# Include any dependencies generated for this target.
include CMakeFiles/ListOfVertices.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ListOfVertices.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ListOfVertices.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ListOfVertices.dir/flags.make

CMakeFiles/ListOfVertices.dir/lists/ListOfVertices.c.o: CMakeFiles/ListOfVertices.dir/flags.make
CMakeFiles/ListOfVertices.dir/lists/ListOfVertices.c.o: /home/artem/programming/c/lab3/lists/ListOfVertices.c
CMakeFiles/ListOfVertices.dir/lists/ListOfVertices.c.o: CMakeFiles/ListOfVertices.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/artem/programming/c/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ListOfVertices.dir/lists/ListOfVertices.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ListOfVertices.dir/lists/ListOfVertices.c.o -MF CMakeFiles/ListOfVertices.dir/lists/ListOfVertices.c.o.d -o CMakeFiles/ListOfVertices.dir/lists/ListOfVertices.c.o -c /home/artem/programming/c/lab3/lists/ListOfVertices.c

CMakeFiles/ListOfVertices.dir/lists/ListOfVertices.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ListOfVertices.dir/lists/ListOfVertices.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/artem/programming/c/lab3/lists/ListOfVertices.c > CMakeFiles/ListOfVertices.dir/lists/ListOfVertices.c.i

CMakeFiles/ListOfVertices.dir/lists/ListOfVertices.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ListOfVertices.dir/lists/ListOfVertices.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/artem/programming/c/lab3/lists/ListOfVertices.c -o CMakeFiles/ListOfVertices.dir/lists/ListOfVertices.c.s

# Object files for target ListOfVertices
ListOfVertices_OBJECTS = \
"CMakeFiles/ListOfVertices.dir/lists/ListOfVertices.c.o"

# External object files for target ListOfVertices
ListOfVertices_EXTERNAL_OBJECTS =

libListOfVertices.a: CMakeFiles/ListOfVertices.dir/lists/ListOfVertices.c.o
libListOfVertices.a: CMakeFiles/ListOfVertices.dir/build.make
libListOfVertices.a: CMakeFiles/ListOfVertices.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/artem/programming/c/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libListOfVertices.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ListOfVertices.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ListOfVertices.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ListOfVertices.dir/build: libListOfVertices.a
.PHONY : CMakeFiles/ListOfVertices.dir/build

CMakeFiles/ListOfVertices.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ListOfVertices.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ListOfVertices.dir/clean

CMakeFiles/ListOfVertices.dir/depend:
	cd /home/artem/programming/c/lab3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/artem/programming/c/lab3 /home/artem/programming/c/lab3 /home/artem/programming/c/lab3/build /home/artem/programming/c/lab3/build /home/artem/programming/c/lab3/build/CMakeFiles/ListOfVertices.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ListOfVertices.dir/depend

