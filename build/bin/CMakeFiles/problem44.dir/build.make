# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dc/Projects/ProjectEuler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dc/Projects/ProjectEuler/build

# Include any dependencies generated for this target.
include bin/CMakeFiles/problem44.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/problem44.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/problem44.dir/flags.make

bin/CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.o: bin/CMakeFiles/problem44.dir/flags.make
bin/CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.o: ../src/problem44/problem44.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dc/Projects/ProjectEuler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.o"
	cd /home/dc/Projects/ProjectEuler/build/bin && /usr/bin/clang++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.o -c /home/dc/Projects/ProjectEuler/src/problem44/problem44.cpp

bin/CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.i"
	cd /home/dc/Projects/ProjectEuler/build/bin && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dc/Projects/ProjectEuler/src/problem44/problem44.cpp > CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.i

bin/CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.s"
	cd /home/dc/Projects/ProjectEuler/build/bin && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dc/Projects/ProjectEuler/src/problem44/problem44.cpp -o CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.s

bin/CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.o.requires:

.PHONY : bin/CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.o.requires

bin/CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.o.provides: bin/CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.o.requires
	$(MAKE) -f bin/CMakeFiles/problem44.dir/build.make bin/CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.o.provides.build
.PHONY : bin/CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.o.provides

bin/CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.o.provides.build: bin/CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.o


# Object files for target problem44
problem44_OBJECTS = \
"CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.o"

# External object files for target problem44
problem44_EXTERNAL_OBJECTS =

bin/problem44: bin/CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.o
bin/problem44: bin/CMakeFiles/problem44.dir/build.make
bin/problem44: bin/CMakeFiles/problem44.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dc/Projects/ProjectEuler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable problem44"
	cd /home/dc/Projects/ProjectEuler/build/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/problem44.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/problem44.dir/build: bin/problem44

.PHONY : bin/CMakeFiles/problem44.dir/build

bin/CMakeFiles/problem44.dir/requires: bin/CMakeFiles/problem44.dir/__/src/problem44/problem44.cpp.o.requires

.PHONY : bin/CMakeFiles/problem44.dir/requires

bin/CMakeFiles/problem44.dir/clean:
	cd /home/dc/Projects/ProjectEuler/build/bin && $(CMAKE_COMMAND) -P CMakeFiles/problem44.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/problem44.dir/clean

bin/CMakeFiles/problem44.dir/depend:
	cd /home/dc/Projects/ProjectEuler/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dc/Projects/ProjectEuler /home/dc/Projects/ProjectEuler/bin /home/dc/Projects/ProjectEuler/build /home/dc/Projects/ProjectEuler/build/bin /home/dc/Projects/ProjectEuler/build/bin/CMakeFiles/problem44.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/problem44.dir/depend
