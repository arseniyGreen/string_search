# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /app/extra/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /app/extra/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/notahacker/Documents/string_search

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/notahacker/Documents/string_search/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/string_search.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/string_search.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/string_search.dir/flags.make

CMakeFiles/string_search.dir/src/main.cpp.o: CMakeFiles/string_search.dir/flags.make
CMakeFiles/string_search.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/notahacker/Documents/string_search/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/string_search.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/string_search.dir/src/main.cpp.o -c /home/notahacker/Documents/string_search/src/main.cpp

CMakeFiles/string_search.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/string_search.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/notahacker/Documents/string_search/src/main.cpp > CMakeFiles/string_search.dir/src/main.cpp.i

CMakeFiles/string_search.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/string_search.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/notahacker/Documents/string_search/src/main.cpp -o CMakeFiles/string_search.dir/src/main.cpp.s

# Object files for target string_search
string_search_OBJECTS = \
"CMakeFiles/string_search.dir/src/main.cpp.o"

# External object files for target string_search
string_search_EXTERNAL_OBJECTS =

string_search: CMakeFiles/string_search.dir/src/main.cpp.o
string_search: CMakeFiles/string_search.dir/build.make
string_search: CMakeFiles/string_search.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/notahacker/Documents/string_search/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable string_search"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/string_search.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/string_search.dir/build: string_search
.PHONY : CMakeFiles/string_search.dir/build

CMakeFiles/string_search.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/string_search.dir/cmake_clean.cmake
.PHONY : CMakeFiles/string_search.dir/clean

CMakeFiles/string_search.dir/depend:
	cd /home/notahacker/Documents/string_search/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/notahacker/Documents/string_search /home/notahacker/Documents/string_search /home/notahacker/Documents/string_search/cmake-build-debug /home/notahacker/Documents/string_search/cmake-build-debug /home/notahacker/Documents/string_search/cmake-build-debug/CMakeFiles/string_search.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/string_search.dir/depend

