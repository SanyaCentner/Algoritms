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
CMAKE_SOURCE_DIR = /Users/aleksandr/Documents/Algoritms/modul_1_zad_1_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/aleksandr/Documents/Algoritms/modul_1_zad_1_1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/modul_1_zad_1_1.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/modul_1_zad_1_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/modul_1_zad_1_1.dir/flags.make

CMakeFiles/modul_1_zad_1_1.dir/main.cpp.o: CMakeFiles/modul_1_zad_1_1.dir/flags.make
CMakeFiles/modul_1_zad_1_1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aleksandr/Documents/Algoritms/modul_1_zad_1_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/modul_1_zad_1_1.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modul_1_zad_1_1.dir/main.cpp.o -c /Users/aleksandr/Documents/Algoritms/modul_1_zad_1_1/main.cpp

CMakeFiles/modul_1_zad_1_1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modul_1_zad_1_1.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aleksandr/Documents/Algoritms/modul_1_zad_1_1/main.cpp > CMakeFiles/modul_1_zad_1_1.dir/main.cpp.i

CMakeFiles/modul_1_zad_1_1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modul_1_zad_1_1.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aleksandr/Documents/Algoritms/modul_1_zad_1_1/main.cpp -o CMakeFiles/modul_1_zad_1_1.dir/main.cpp.s

# Object files for target modul_1_zad_1_1
modul_1_zad_1_1_OBJECTS = \
"CMakeFiles/modul_1_zad_1_1.dir/main.cpp.o"

# External object files for target modul_1_zad_1_1
modul_1_zad_1_1_EXTERNAL_OBJECTS =

modul_1_zad_1_1: CMakeFiles/modul_1_zad_1_1.dir/main.cpp.o
modul_1_zad_1_1: CMakeFiles/modul_1_zad_1_1.dir/build.make
modul_1_zad_1_1: CMakeFiles/modul_1_zad_1_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/aleksandr/Documents/Algoritms/modul_1_zad_1_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable modul_1_zad_1_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/modul_1_zad_1_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/modul_1_zad_1_1.dir/build: modul_1_zad_1_1
.PHONY : CMakeFiles/modul_1_zad_1_1.dir/build

CMakeFiles/modul_1_zad_1_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/modul_1_zad_1_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/modul_1_zad_1_1.dir/clean

CMakeFiles/modul_1_zad_1_1.dir/depend:
	cd /Users/aleksandr/Documents/Algoritms/modul_1_zad_1_1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/aleksandr/Documents/Algoritms/modul_1_zad_1_1 /Users/aleksandr/Documents/Algoritms/modul_1_zad_1_1 /Users/aleksandr/Documents/Algoritms/modul_1_zad_1_1/cmake-build-debug /Users/aleksandr/Documents/Algoritms/modul_1_zad_1_1/cmake-build-debug /Users/aleksandr/Documents/Algoritms/modul_1_zad_1_1/cmake-build-debug/CMakeFiles/modul_1_zad_1_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/modul_1_zad_1_1.dir/depend

