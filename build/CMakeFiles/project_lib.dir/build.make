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
include CMakeFiles/project_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project_lib.dir/flags.make

CMakeFiles/project_lib.dir/src/primes.cpp.o: CMakeFiles/project_lib.dir/flags.make
CMakeFiles/project_lib.dir/src/primes.cpp.o: ../src/primes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dc/Projects/ProjectEuler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project_lib.dir/src/primes.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_lib.dir/src/primes.cpp.o -c /home/dc/Projects/ProjectEuler/src/primes.cpp

CMakeFiles/project_lib.dir/src/primes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_lib.dir/src/primes.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dc/Projects/ProjectEuler/src/primes.cpp > CMakeFiles/project_lib.dir/src/primes.cpp.i

CMakeFiles/project_lib.dir/src/primes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_lib.dir/src/primes.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dc/Projects/ProjectEuler/src/primes.cpp -o CMakeFiles/project_lib.dir/src/primes.cpp.s

CMakeFiles/project_lib.dir/src/primes.cpp.o.requires:

.PHONY : CMakeFiles/project_lib.dir/src/primes.cpp.o.requires

CMakeFiles/project_lib.dir/src/primes.cpp.o.provides: CMakeFiles/project_lib.dir/src/primes.cpp.o.requires
	$(MAKE) -f CMakeFiles/project_lib.dir/build.make CMakeFiles/project_lib.dir/src/primes.cpp.o.provides.build
.PHONY : CMakeFiles/project_lib.dir/src/primes.cpp.o.provides

CMakeFiles/project_lib.dir/src/primes.cpp.o.provides.build: CMakeFiles/project_lib.dir/src/primes.cpp.o


CMakeFiles/project_lib.dir/src/permute.cpp.o: CMakeFiles/project_lib.dir/flags.make
CMakeFiles/project_lib.dir/src/permute.cpp.o: ../src/permute.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dc/Projects/ProjectEuler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project_lib.dir/src/permute.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_lib.dir/src/permute.cpp.o -c /home/dc/Projects/ProjectEuler/src/permute.cpp

CMakeFiles/project_lib.dir/src/permute.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_lib.dir/src/permute.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dc/Projects/ProjectEuler/src/permute.cpp > CMakeFiles/project_lib.dir/src/permute.cpp.i

CMakeFiles/project_lib.dir/src/permute.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_lib.dir/src/permute.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dc/Projects/ProjectEuler/src/permute.cpp -o CMakeFiles/project_lib.dir/src/permute.cpp.s

CMakeFiles/project_lib.dir/src/permute.cpp.o.requires:

.PHONY : CMakeFiles/project_lib.dir/src/permute.cpp.o.requires

CMakeFiles/project_lib.dir/src/permute.cpp.o.provides: CMakeFiles/project_lib.dir/src/permute.cpp.o.requires
	$(MAKE) -f CMakeFiles/project_lib.dir/build.make CMakeFiles/project_lib.dir/src/permute.cpp.o.provides.build
.PHONY : CMakeFiles/project_lib.dir/src/permute.cpp.o.provides

CMakeFiles/project_lib.dir/src/permute.cpp.o.provides.build: CMakeFiles/project_lib.dir/src/permute.cpp.o


# Object files for target project_lib
project_lib_OBJECTS = \
"CMakeFiles/project_lib.dir/src/primes.cpp.o" \
"CMakeFiles/project_lib.dir/src/permute.cpp.o"

# External object files for target project_lib
project_lib_EXTERNAL_OBJECTS =

libproject_lib.a: CMakeFiles/project_lib.dir/src/primes.cpp.o
libproject_lib.a: CMakeFiles/project_lib.dir/src/permute.cpp.o
libproject_lib.a: CMakeFiles/project_lib.dir/build.make
libproject_lib.a: CMakeFiles/project_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dc/Projects/ProjectEuler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libproject_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/project_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project_lib.dir/build: libproject_lib.a

.PHONY : CMakeFiles/project_lib.dir/build

CMakeFiles/project_lib.dir/requires: CMakeFiles/project_lib.dir/src/primes.cpp.o.requires
CMakeFiles/project_lib.dir/requires: CMakeFiles/project_lib.dir/src/permute.cpp.o.requires

.PHONY : CMakeFiles/project_lib.dir/requires

CMakeFiles/project_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project_lib.dir/clean

CMakeFiles/project_lib.dir/depend:
	cd /home/dc/Projects/ProjectEuler/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dc/Projects/ProjectEuler /home/dc/Projects/ProjectEuler /home/dc/Projects/ProjectEuler/build /home/dc/Projects/ProjectEuler/build /home/dc/Projects/ProjectEuler/build/CMakeFiles/project_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project_lib.dir/depend
