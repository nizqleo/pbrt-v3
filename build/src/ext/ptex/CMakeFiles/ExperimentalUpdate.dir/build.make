# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/nizq/Downloads/computer graphic/pbrt-v3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/nizq/Downloads/computer graphic/pbrt-v3/build"

# Utility rule file for ExperimentalUpdate.

# Include the progress variables for this target.
include src/ext/ptex/CMakeFiles/ExperimentalUpdate.dir/progress.make

src/ext/ptex/CMakeFiles/ExperimentalUpdate:
	cd "/home/nizq/Downloads/computer graphic/pbrt-v3/build/src/ext/ptex" && /usr/local/bin/ctest -D ExperimentalUpdate

ExperimentalUpdate: src/ext/ptex/CMakeFiles/ExperimentalUpdate
ExperimentalUpdate: src/ext/ptex/CMakeFiles/ExperimentalUpdate.dir/build.make

.PHONY : ExperimentalUpdate

# Rule to build all files generated by this target.
src/ext/ptex/CMakeFiles/ExperimentalUpdate.dir/build: ExperimentalUpdate

.PHONY : src/ext/ptex/CMakeFiles/ExperimentalUpdate.dir/build

src/ext/ptex/CMakeFiles/ExperimentalUpdate.dir/clean:
	cd "/home/nizq/Downloads/computer graphic/pbrt-v3/build/src/ext/ptex" && $(CMAKE_COMMAND) -P CMakeFiles/ExperimentalUpdate.dir/cmake_clean.cmake
.PHONY : src/ext/ptex/CMakeFiles/ExperimentalUpdate.dir/clean

src/ext/ptex/CMakeFiles/ExperimentalUpdate.dir/depend:
	cd "/home/nizq/Downloads/computer graphic/pbrt-v3/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/nizq/Downloads/computer graphic/pbrt-v3" "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/ptex" "/home/nizq/Downloads/computer graphic/pbrt-v3/build" "/home/nizq/Downloads/computer graphic/pbrt-v3/build/src/ext/ptex" "/home/nizq/Downloads/computer graphic/pbrt-v3/build/src/ext/ptex/CMakeFiles/ExperimentalUpdate.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/ext/ptex/CMakeFiles/ExperimentalUpdate.dir/depend

