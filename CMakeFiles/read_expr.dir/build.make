# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/oleg/Public/Oleg/course_2/ded/differentiator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oleg/Public/Oleg/course_2/ded/differentiator

# Include any dependencies generated for this target.
include CMakeFiles/read_expr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/read_expr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/read_expr.dir/flags.make

CMakeFiles/read_expr.dir/main_files/reader.cpp.o: CMakeFiles/read_expr.dir/flags.make
CMakeFiles/read_expr.dir/main_files/reader.cpp.o: main_files/reader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oleg/Public/Oleg/course_2/ded/differentiator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/read_expr.dir/main_files/reader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/read_expr.dir/main_files/reader.cpp.o -c /home/oleg/Public/Oleg/course_2/ded/differentiator/main_files/reader.cpp

CMakeFiles/read_expr.dir/main_files/reader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/read_expr.dir/main_files/reader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oleg/Public/Oleg/course_2/ded/differentiator/main_files/reader.cpp > CMakeFiles/read_expr.dir/main_files/reader.cpp.i

CMakeFiles/read_expr.dir/main_files/reader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/read_expr.dir/main_files/reader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oleg/Public/Oleg/course_2/ded/differentiator/main_files/reader.cpp -o CMakeFiles/read_expr.dir/main_files/reader.cpp.s

CMakeFiles/read_expr.dir/main_files/reader.cpp.o.requires:

.PHONY : CMakeFiles/read_expr.dir/main_files/reader.cpp.o.requires

CMakeFiles/read_expr.dir/main_files/reader.cpp.o.provides: CMakeFiles/read_expr.dir/main_files/reader.cpp.o.requires
	$(MAKE) -f CMakeFiles/read_expr.dir/build.make CMakeFiles/read_expr.dir/main_files/reader.cpp.o.provides.build
.PHONY : CMakeFiles/read_expr.dir/main_files/reader.cpp.o.provides

CMakeFiles/read_expr.dir/main_files/reader.cpp.o.provides.build: CMakeFiles/read_expr.dir/main_files/reader.cpp.o


# Object files for target read_expr
read_expr_OBJECTS = \
"CMakeFiles/read_expr.dir/main_files/reader.cpp.o"

# External object files for target read_expr
read_expr_EXTERNAL_OBJECTS =

read_expr: CMakeFiles/read_expr.dir/main_files/reader.cpp.o
read_expr: CMakeFiles/read_expr.dir/build.make
read_expr: CMakeFiles/read_expr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oleg/Public/Oleg/course_2/ded/differentiator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable read_expr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/read_expr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/read_expr.dir/build: read_expr

.PHONY : CMakeFiles/read_expr.dir/build

CMakeFiles/read_expr.dir/requires: CMakeFiles/read_expr.dir/main_files/reader.cpp.o.requires

.PHONY : CMakeFiles/read_expr.dir/requires

CMakeFiles/read_expr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/read_expr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/read_expr.dir/clean

CMakeFiles/read_expr.dir/depend:
	cd /home/oleg/Public/Oleg/course_2/ded/differentiator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oleg/Public/Oleg/course_2/ded/differentiator /home/oleg/Public/Oleg/course_2/ded/differentiator /home/oleg/Public/Oleg/course_2/ded/differentiator /home/oleg/Public/Oleg/course_2/ded/differentiator /home/oleg/Public/Oleg/course_2/ded/differentiator/CMakeFiles/read_expr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/read_expr.dir/depend

