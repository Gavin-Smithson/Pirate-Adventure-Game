# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/leharman/dev/CppFinalProj/CSCSI-207-final/ChantsAdventure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leharman/dev/CppFinalProj/CSCSI-207-final/ChantsAdventure/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/adventuretests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/adventuretests.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/adventuretests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/adventuretests.dir/flags.make

tests/CMakeFiles/adventuretests.dir/adventuretests.cpp.o: tests/CMakeFiles/adventuretests.dir/flags.make
tests/CMakeFiles/adventuretests.dir/adventuretests.cpp.o: ../tests/adventuretests.cpp
tests/CMakeFiles/adventuretests.dir/adventuretests.cpp.o: tests/CMakeFiles/adventuretests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leharman/dev/CppFinalProj/CSCSI-207-final/ChantsAdventure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/adventuretests.dir/adventuretests.cpp.o"
	cd /home/leharman/dev/CppFinalProj/CSCSI-207-final/ChantsAdventure/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/adventuretests.dir/adventuretests.cpp.o -MF CMakeFiles/adventuretests.dir/adventuretests.cpp.o.d -o CMakeFiles/adventuretests.dir/adventuretests.cpp.o -c /home/leharman/dev/CppFinalProj/CSCSI-207-final/ChantsAdventure/tests/adventuretests.cpp

tests/CMakeFiles/adventuretests.dir/adventuretests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/adventuretests.dir/adventuretests.cpp.i"
	cd /home/leharman/dev/CppFinalProj/CSCSI-207-final/ChantsAdventure/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leharman/dev/CppFinalProj/CSCSI-207-final/ChantsAdventure/tests/adventuretests.cpp > CMakeFiles/adventuretests.dir/adventuretests.cpp.i

tests/CMakeFiles/adventuretests.dir/adventuretests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/adventuretests.dir/adventuretests.cpp.s"
	cd /home/leharman/dev/CppFinalProj/CSCSI-207-final/ChantsAdventure/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leharman/dev/CppFinalProj/CSCSI-207-final/ChantsAdventure/tests/adventuretests.cpp -o CMakeFiles/adventuretests.dir/adventuretests.cpp.s

# Object files for target adventuretests
adventuretests_OBJECTS = \
"CMakeFiles/adventuretests.dir/adventuretests.cpp.o"

# External object files for target adventuretests
adventuretests_EXTERNAL_OBJECTS =

tests/adventuretests: tests/CMakeFiles/adventuretests.dir/adventuretests.cpp.o
tests/adventuretests: tests/CMakeFiles/adventuretests.dir/build.make
tests/adventuretests: lib/libgtest_main.a
tests/adventuretests: src/libGameMap.a
tests/adventuretests: lib/libgtest.a
tests/adventuretests: tests/CMakeFiles/adventuretests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leharman/dev/CppFinalProj/CSCSI-207-final/ChantsAdventure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable adventuretests"
	cd /home/leharman/dev/CppFinalProj/CSCSI-207-final/ChantsAdventure/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/adventuretests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/adventuretests.dir/build: tests/adventuretests
.PHONY : tests/CMakeFiles/adventuretests.dir/build

tests/CMakeFiles/adventuretests.dir/clean:
	cd /home/leharman/dev/CppFinalProj/CSCSI-207-final/ChantsAdventure/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/adventuretests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/adventuretests.dir/clean

tests/CMakeFiles/adventuretests.dir/depend:
	cd /home/leharman/dev/CppFinalProj/CSCSI-207-final/ChantsAdventure/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leharman/dev/CppFinalProj/CSCSI-207-final/ChantsAdventure /home/leharman/dev/CppFinalProj/CSCSI-207-final/ChantsAdventure/tests /home/leharman/dev/CppFinalProj/CSCSI-207-final/ChantsAdventure/build /home/leharman/dev/CppFinalProj/CSCSI-207-final/ChantsAdventure/build/tests /home/leharman/dev/CppFinalProj/CSCSI-207-final/ChantsAdventure/build/tests/CMakeFiles/adventuretests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/adventuretests.dir/depend
