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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/aleksandr/Documents/Algoritms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/aleksandr/Documents/Algoritms/cmake-build-debug

# Include any dependencies generated for this target.
include _deps/gtest-build/googletest/CMakeFiles/gtest.dir/depend.make
# Include the progress variables for this target.
include _deps/gtest-build/googletest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/gtest-build/googletest/CMakeFiles/gtest.dir/flags.make

_deps/gtest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: _deps/gtest-build/googletest/CMakeFiles/gtest.dir/flags.make
_deps/gtest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: _deps/gtest-src/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aleksandr/Documents/Algoritms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/gtest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /Users/aleksandr/Documents/Algoritms/cmake-build-debug/_deps/gtest-build/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /Users/aleksandr/Documents/Algoritms/cmake-build-debug/_deps/gtest-src/googletest/src/gtest-all.cc

_deps/gtest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /Users/aleksandr/Documents/Algoritms/cmake-build-debug/_deps/gtest-build/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aleksandr/Documents/Algoritms/cmake-build-debug/_deps/gtest-src/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

_deps/gtest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /Users/aleksandr/Documents/Algoritms/cmake-build-debug/_deps/gtest-build/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aleksandr/Documents/Algoritms/cmake-build-debug/_deps/gtest-src/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/libgtestd.a: _deps/gtest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
lib/libgtestd.a: _deps/gtest-build/googletest/CMakeFiles/gtest.dir/build.make
lib/libgtestd.a: _deps/gtest-build/googletest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/aleksandr/Documents/Algoritms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libgtestd.a"
	cd /Users/aleksandr/Documents/Algoritms/cmake-build-debug/_deps/gtest-build/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /Users/aleksandr/Documents/Algoritms/cmake-build-debug/_deps/gtest-build/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/gtest-build/googletest/CMakeFiles/gtest.dir/build: lib/libgtestd.a
.PHONY : _deps/gtest-build/googletest/CMakeFiles/gtest.dir/build

_deps/gtest-build/googletest/CMakeFiles/gtest.dir/clean:
	cd /Users/aleksandr/Documents/Algoritms/cmake-build-debug/_deps/gtest-build/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : _deps/gtest-build/googletest/CMakeFiles/gtest.dir/clean

_deps/gtest-build/googletest/CMakeFiles/gtest.dir/depend:
	cd /Users/aleksandr/Documents/Algoritms/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/aleksandr/Documents/Algoritms /Users/aleksandr/Documents/Algoritms/cmake-build-debug/_deps/gtest-src/googletest /Users/aleksandr/Documents/Algoritms/cmake-build-debug /Users/aleksandr/Documents/Algoritms/cmake-build-debug/_deps/gtest-build/googletest /Users/aleksandr/Documents/Algoritms/cmake-build-debug/_deps/gtest-build/googletest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/gtest-build/googletest/CMakeFiles/gtest.dir/depend

