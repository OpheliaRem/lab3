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
include CMakeFiles/ListOfFaces.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ListOfFaces.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ListOfFaces.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ListOfFaces.dir/flags.make

CMakeFiles/ListOfFaces.dir/lists/ListOfFaces.c.o: CMakeFiles/ListOfFaces.dir/flags.make
CMakeFiles/ListOfFaces.dir/lists/ListOfFaces.c.o: /home/artem/programming/c/lab3/lists/ListOfFaces.c
CMakeFiles/ListOfFaces.dir/lists/ListOfFaces.c.o: CMakeFiles/ListOfFaces.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/artem/programming/c/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ListOfFaces.dir/lists/ListOfFaces.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ListOfFaces.dir/lists/ListOfFaces.c.o -MF CMakeFiles/ListOfFaces.dir/lists/ListOfFaces.c.o.d -o CMakeFiles/ListOfFaces.dir/lists/ListOfFaces.c.o -c /home/artem/programming/c/lab3/lists/ListOfFaces.c

CMakeFiles/ListOfFaces.dir/lists/ListOfFaces.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ListOfFaces.dir/lists/ListOfFaces.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/artem/programming/c/lab3/lists/ListOfFaces.c > CMakeFiles/ListOfFaces.dir/lists/ListOfFaces.c.i

CMakeFiles/ListOfFaces.dir/lists/ListOfFaces.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ListOfFaces.dir/lists/ListOfFaces.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/artem/programming/c/lab3/lists/ListOfFaces.c -o CMakeFiles/ListOfFaces.dir/lists/ListOfFaces.c.s

# Object files for target ListOfFaces
ListOfFaces_OBJECTS = \
"CMakeFiles/ListOfFaces.dir/lists/ListOfFaces.c.o"

# External object files for target ListOfFaces
ListOfFaces_EXTERNAL_OBJECTS =

libListOfFaces.a: CMakeFiles/ListOfFaces.dir/lists/ListOfFaces.c.o
libListOfFaces.a: CMakeFiles/ListOfFaces.dir/build.make
libListOfFaces.a: CMakeFiles/ListOfFaces.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/artem/programming/c/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libListOfFaces.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ListOfFaces.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ListOfFaces.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ListOfFaces.dir/build: libListOfFaces.a
.PHONY : CMakeFiles/ListOfFaces.dir/build

CMakeFiles/ListOfFaces.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ListOfFaces.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ListOfFaces.dir/clean

CMakeFiles/ListOfFaces.dir/depend:
	cd /home/artem/programming/c/lab3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/artem/programming/c/lab3 /home/artem/programming/c/lab3 /home/artem/programming/c/lab3/build /home/artem/programming/c/lab3/build /home/artem/programming/c/lab3/build/CMakeFiles/ListOfFaces.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ListOfFaces.dir/depend

