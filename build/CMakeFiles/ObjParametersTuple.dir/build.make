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
include CMakeFiles/ObjParametersTuple.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ObjParametersTuple.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ObjParametersTuple.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ObjParametersTuple.dir/flags.make

CMakeFiles/ObjParametersTuple.dir/ObjParametersTuple.c.o: CMakeFiles/ObjParametersTuple.dir/flags.make
CMakeFiles/ObjParametersTuple.dir/ObjParametersTuple.c.o: /home/artem/programming/c/lab3/ObjParametersTuple.c
CMakeFiles/ObjParametersTuple.dir/ObjParametersTuple.c.o: CMakeFiles/ObjParametersTuple.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/artem/programming/c/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ObjParametersTuple.dir/ObjParametersTuple.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ObjParametersTuple.dir/ObjParametersTuple.c.o -MF CMakeFiles/ObjParametersTuple.dir/ObjParametersTuple.c.o.d -o CMakeFiles/ObjParametersTuple.dir/ObjParametersTuple.c.o -c /home/artem/programming/c/lab3/ObjParametersTuple.c

CMakeFiles/ObjParametersTuple.dir/ObjParametersTuple.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ObjParametersTuple.dir/ObjParametersTuple.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/artem/programming/c/lab3/ObjParametersTuple.c > CMakeFiles/ObjParametersTuple.dir/ObjParametersTuple.c.i

CMakeFiles/ObjParametersTuple.dir/ObjParametersTuple.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ObjParametersTuple.dir/ObjParametersTuple.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/artem/programming/c/lab3/ObjParametersTuple.c -o CMakeFiles/ObjParametersTuple.dir/ObjParametersTuple.c.s

# Object files for target ObjParametersTuple
ObjParametersTuple_OBJECTS = \
"CMakeFiles/ObjParametersTuple.dir/ObjParametersTuple.c.o"

# External object files for target ObjParametersTuple
ObjParametersTuple_EXTERNAL_OBJECTS =

libObjParametersTuple.a: CMakeFiles/ObjParametersTuple.dir/ObjParametersTuple.c.o
libObjParametersTuple.a: CMakeFiles/ObjParametersTuple.dir/build.make
libObjParametersTuple.a: CMakeFiles/ObjParametersTuple.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/artem/programming/c/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libObjParametersTuple.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ObjParametersTuple.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ObjParametersTuple.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ObjParametersTuple.dir/build: libObjParametersTuple.a
.PHONY : CMakeFiles/ObjParametersTuple.dir/build

CMakeFiles/ObjParametersTuple.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ObjParametersTuple.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ObjParametersTuple.dir/clean

CMakeFiles/ObjParametersTuple.dir/depend:
	cd /home/artem/programming/c/lab3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/artem/programming/c/lab3 /home/artem/programming/c/lab3 /home/artem/programming/c/lab3/build /home/artem/programming/c/lab3/build /home/artem/programming/c/lab3/build/CMakeFiles/ObjParametersTuple.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ObjParametersTuple.dir/depend

