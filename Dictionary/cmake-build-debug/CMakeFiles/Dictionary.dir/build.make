# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /cygdrive/c/Users/Mahdi/AppData/Local/JetBrains/CLion2021.1/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Mahdi/AppData/Local/JetBrains/CLion2021.1/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/f/univercity/term 2/AP !/miniproject/Dictionary/Dictionary"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/f/univercity/term 2/AP !/miniproject/Dictionary/Dictionary/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Dictionary.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Dictionary.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Dictionary.dir/flags.make

CMakeFiles/Dictionary.dir/main.cpp.o: CMakeFiles/Dictionary.dir/flags.make
CMakeFiles/Dictionary.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/f/univercity/term 2/AP !/miniproject/Dictionary/Dictionary/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Dictionary.dir/main.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Dictionary.dir/main.cpp.o -c "/cygdrive/f/univercity/term 2/AP !/miniproject/Dictionary/Dictionary/main.cpp"

CMakeFiles/Dictionary.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dictionary.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/f/univercity/term 2/AP !/miniproject/Dictionary/Dictionary/main.cpp" > CMakeFiles/Dictionary.dir/main.cpp.i

CMakeFiles/Dictionary.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dictionary.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/f/univercity/term 2/AP !/miniproject/Dictionary/Dictionary/main.cpp" -o CMakeFiles/Dictionary.dir/main.cpp.s

# Object files for target Dictionary
Dictionary_OBJECTS = \
"CMakeFiles/Dictionary.dir/main.cpp.o"

# External object files for target Dictionary
Dictionary_EXTERNAL_OBJECTS =

Dictionary.exe: CMakeFiles/Dictionary.dir/main.cpp.o
Dictionary.exe: CMakeFiles/Dictionary.dir/build.make
Dictionary.exe: CMakeFiles/Dictionary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/f/univercity/term 2/AP !/miniproject/Dictionary/Dictionary/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Dictionary.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Dictionary.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Dictionary.dir/build: Dictionary.exe

.PHONY : CMakeFiles/Dictionary.dir/build

CMakeFiles/Dictionary.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Dictionary.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Dictionary.dir/clean

CMakeFiles/Dictionary.dir/depend:
	cd "/cygdrive/f/univercity/term 2/AP !/miniproject/Dictionary/Dictionary/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/f/univercity/term 2/AP !/miniproject/Dictionary/Dictionary" "/cygdrive/f/univercity/term 2/AP !/miniproject/Dictionary/Dictionary" "/cygdrive/f/univercity/term 2/AP !/miniproject/Dictionary/Dictionary/cmake-build-debug" "/cygdrive/f/univercity/term 2/AP !/miniproject/Dictionary/Dictionary/cmake-build-debug" "/cygdrive/f/univercity/term 2/AP !/miniproject/Dictionary/Dictionary/cmake-build-debug/CMakeFiles/Dictionary.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Dictionary.dir/depend

