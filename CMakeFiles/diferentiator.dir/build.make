# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /snap/clion/112/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/112/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/oleg/Public/Oleg/course_2/ded/differentiator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oleg/Public/Oleg/course_2/ded/differentiator

# Include any dependencies generated for this target.
include CMakeFiles/diferentiator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/diferentiator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/diferentiator.dir/flags.make

CMakeFiles/diferentiator.dir/main.cpp.o: CMakeFiles/diferentiator.dir/flags.make
CMakeFiles/diferentiator.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oleg/Public/Oleg/course_2/ded/differentiator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/diferentiator.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/diferentiator.dir/main.cpp.o -c /home/oleg/Public/Oleg/course_2/ded/differentiator/main.cpp

CMakeFiles/diferentiator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/diferentiator.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oleg/Public/Oleg/course_2/ded/differentiator/main.cpp > CMakeFiles/diferentiator.dir/main.cpp.i

CMakeFiles/diferentiator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/diferentiator.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oleg/Public/Oleg/course_2/ded/differentiator/main.cpp -o CMakeFiles/diferentiator.dir/main.cpp.s

CMakeFiles/diferentiator.dir/differentiator_tree/expression_parser.cpp.o: CMakeFiles/diferentiator.dir/flags.make
CMakeFiles/diferentiator.dir/differentiator_tree/expression_parser.cpp.o: differentiator_tree/expression_parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oleg/Public/Oleg/course_2/ded/differentiator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/diferentiator.dir/differentiator_tree/expression_parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/diferentiator.dir/differentiator_tree/expression_parser.cpp.o -c /home/oleg/Public/Oleg/course_2/ded/differentiator/differentiator_tree/expression_parser.cpp

CMakeFiles/diferentiator.dir/differentiator_tree/expression_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/diferentiator.dir/differentiator_tree/expression_parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oleg/Public/Oleg/course_2/ded/differentiator/differentiator_tree/expression_parser.cpp > CMakeFiles/diferentiator.dir/differentiator_tree/expression_parser.cpp.i

CMakeFiles/diferentiator.dir/differentiator_tree/expression_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/diferentiator.dir/differentiator_tree/expression_parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oleg/Public/Oleg/course_2/ded/differentiator/differentiator_tree/expression_parser.cpp -o CMakeFiles/diferentiator.dir/differentiator_tree/expression_parser.cpp.s

CMakeFiles/diferentiator.dir/containers/my_string/my_string.cpp.o: CMakeFiles/diferentiator.dir/flags.make
CMakeFiles/diferentiator.dir/containers/my_string/my_string.cpp.o: containers/my_string/my_string.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oleg/Public/Oleg/course_2/ded/differentiator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/diferentiator.dir/containers/my_string/my_string.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/diferentiator.dir/containers/my_string/my_string.cpp.o -c /home/oleg/Public/Oleg/course_2/ded/differentiator/containers/my_string/my_string.cpp

CMakeFiles/diferentiator.dir/containers/my_string/my_string.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/diferentiator.dir/containers/my_string/my_string.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oleg/Public/Oleg/course_2/ded/differentiator/containers/my_string/my_string.cpp > CMakeFiles/diferentiator.dir/containers/my_string/my_string.cpp.i

CMakeFiles/diferentiator.dir/containers/my_string/my_string.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/diferentiator.dir/containers/my_string/my_string.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oleg/Public/Oleg/course_2/ded/differentiator/containers/my_string/my_string.cpp -o CMakeFiles/diferentiator.dir/containers/my_string/my_string.cpp.s

CMakeFiles/diferentiator.dir/containers/my_vector/my_vector.cpp.o: CMakeFiles/diferentiator.dir/flags.make
CMakeFiles/diferentiator.dir/containers/my_vector/my_vector.cpp.o: containers/my_vector/my_vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oleg/Public/Oleg/course_2/ded/differentiator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/diferentiator.dir/containers/my_vector/my_vector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/diferentiator.dir/containers/my_vector/my_vector.cpp.o -c /home/oleg/Public/Oleg/course_2/ded/differentiator/containers/my_vector/my_vector.cpp

CMakeFiles/diferentiator.dir/containers/my_vector/my_vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/diferentiator.dir/containers/my_vector/my_vector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oleg/Public/Oleg/course_2/ded/differentiator/containers/my_vector/my_vector.cpp > CMakeFiles/diferentiator.dir/containers/my_vector/my_vector.cpp.i

CMakeFiles/diferentiator.dir/containers/my_vector/my_vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/diferentiator.dir/containers/my_vector/my_vector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oleg/Public/Oleg/course_2/ded/differentiator/containers/my_vector/my_vector.cpp -o CMakeFiles/diferentiator.dir/containers/my_vector/my_vector.cpp.s

CMakeFiles/diferentiator.dir/containers/bor/bor.cpp.o: CMakeFiles/diferentiator.dir/flags.make
CMakeFiles/diferentiator.dir/containers/bor/bor.cpp.o: containers/bor/bor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oleg/Public/Oleg/course_2/ded/differentiator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/diferentiator.dir/containers/bor/bor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/diferentiator.dir/containers/bor/bor.cpp.o -c /home/oleg/Public/Oleg/course_2/ded/differentiator/containers/bor/bor.cpp

CMakeFiles/diferentiator.dir/containers/bor/bor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/diferentiator.dir/containers/bor/bor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oleg/Public/Oleg/course_2/ded/differentiator/containers/bor/bor.cpp > CMakeFiles/diferentiator.dir/containers/bor/bor.cpp.i

CMakeFiles/diferentiator.dir/containers/bor/bor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/diferentiator.dir/containers/bor/bor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oleg/Public/Oleg/course_2/ded/differentiator/containers/bor/bor.cpp -o CMakeFiles/diferentiator.dir/containers/bor/bor.cpp.s

CMakeFiles/diferentiator.dir/containers/auto_free/auto_free.cpp.o: CMakeFiles/diferentiator.dir/flags.make
CMakeFiles/diferentiator.dir/containers/auto_free/auto_free.cpp.o: containers/auto_free/auto_free.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oleg/Public/Oleg/course_2/ded/differentiator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/diferentiator.dir/containers/auto_free/auto_free.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/diferentiator.dir/containers/auto_free/auto_free.cpp.o -c /home/oleg/Public/Oleg/course_2/ded/differentiator/containers/auto_free/auto_free.cpp

CMakeFiles/diferentiator.dir/containers/auto_free/auto_free.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/diferentiator.dir/containers/auto_free/auto_free.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oleg/Public/Oleg/course_2/ded/differentiator/containers/auto_free/auto_free.cpp > CMakeFiles/diferentiator.dir/containers/auto_free/auto_free.cpp.i

CMakeFiles/diferentiator.dir/containers/auto_free/auto_free.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/diferentiator.dir/containers/auto_free/auto_free.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oleg/Public/Oleg/course_2/ded/differentiator/containers/auto_free/auto_free.cpp -o CMakeFiles/diferentiator.dir/containers/auto_free/auto_free.cpp.s

CMakeFiles/diferentiator.dir/work_with_file_functions/file_work_functions.cpp.o: CMakeFiles/diferentiator.dir/flags.make
CMakeFiles/diferentiator.dir/work_with_file_functions/file_work_functions.cpp.o: work_with_file_functions/file_work_functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oleg/Public/Oleg/course_2/ded/differentiator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/diferentiator.dir/work_with_file_functions/file_work_functions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/diferentiator.dir/work_with_file_functions/file_work_functions.cpp.o -c /home/oleg/Public/Oleg/course_2/ded/differentiator/work_with_file_functions/file_work_functions.cpp

CMakeFiles/diferentiator.dir/work_with_file_functions/file_work_functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/diferentiator.dir/work_with_file_functions/file_work_functions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oleg/Public/Oleg/course_2/ded/differentiator/work_with_file_functions/file_work_functions.cpp > CMakeFiles/diferentiator.dir/work_with_file_functions/file_work_functions.cpp.i

CMakeFiles/diferentiator.dir/work_with_file_functions/file_work_functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/diferentiator.dir/work_with_file_functions/file_work_functions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oleg/Public/Oleg/course_2/ded/differentiator/work_with_file_functions/file_work_functions.cpp -o CMakeFiles/diferentiator.dir/work_with_file_functions/file_work_functions.cpp.s

CMakeFiles/diferentiator.dir/differentiator_tree/expression_tree.cpp.o: CMakeFiles/diferentiator.dir/flags.make
CMakeFiles/diferentiator.dir/differentiator_tree/expression_tree.cpp.o: differentiator_tree/expression_tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oleg/Public/Oleg/course_2/ded/differentiator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/diferentiator.dir/differentiator_tree/expression_tree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/diferentiator.dir/differentiator_tree/expression_tree.cpp.o -c /home/oleg/Public/Oleg/course_2/ded/differentiator/differentiator_tree/expression_tree.cpp

CMakeFiles/diferentiator.dir/differentiator_tree/expression_tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/diferentiator.dir/differentiator_tree/expression_tree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oleg/Public/Oleg/course_2/ded/differentiator/differentiator_tree/expression_tree.cpp > CMakeFiles/diferentiator.dir/differentiator_tree/expression_tree.cpp.i

CMakeFiles/diferentiator.dir/differentiator_tree/expression_tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/diferentiator.dir/differentiator_tree/expression_tree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oleg/Public/Oleg/course_2/ded/differentiator/differentiator_tree/expression_tree.cpp -o CMakeFiles/diferentiator.dir/differentiator_tree/expression_tree.cpp.s

CMakeFiles/diferentiator.dir/differentiator_tree/tree_dfs.cpp.o: CMakeFiles/diferentiator.dir/flags.make
CMakeFiles/diferentiator.dir/differentiator_tree/tree_dfs.cpp.o: differentiator_tree/tree_dfs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oleg/Public/Oleg/course_2/ded/differentiator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/diferentiator.dir/differentiator_tree/tree_dfs.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/diferentiator.dir/differentiator_tree/tree_dfs.cpp.o -c /home/oleg/Public/Oleg/course_2/ded/differentiator/differentiator_tree/tree_dfs.cpp

CMakeFiles/diferentiator.dir/differentiator_tree/tree_dfs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/diferentiator.dir/differentiator_tree/tree_dfs.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oleg/Public/Oleg/course_2/ded/differentiator/differentiator_tree/tree_dfs.cpp > CMakeFiles/diferentiator.dir/differentiator_tree/tree_dfs.cpp.i

CMakeFiles/diferentiator.dir/differentiator_tree/tree_dfs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/diferentiator.dir/differentiator_tree/tree_dfs.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oleg/Public/Oleg/course_2/ded/differentiator/differentiator_tree/tree_dfs.cpp -o CMakeFiles/diferentiator.dir/differentiator_tree/tree_dfs.cpp.s

# Object files for target diferentiator
diferentiator_OBJECTS = \
"CMakeFiles/diferentiator.dir/main.cpp.o" \
"CMakeFiles/diferentiator.dir/differentiator_tree/expression_parser.cpp.o" \
"CMakeFiles/diferentiator.dir/containers/my_string/my_string.cpp.o" \
"CMakeFiles/diferentiator.dir/containers/my_vector/my_vector.cpp.o" \
"CMakeFiles/diferentiator.dir/containers/bor/bor.cpp.o" \
"CMakeFiles/diferentiator.dir/containers/auto_free/auto_free.cpp.o" \
"CMakeFiles/diferentiator.dir/work_with_file_functions/file_work_functions.cpp.o" \
"CMakeFiles/diferentiator.dir/differentiator_tree/expression_tree.cpp.o" \
"CMakeFiles/diferentiator.dir/differentiator_tree/tree_dfs.cpp.o"

# External object files for target diferentiator
diferentiator_EXTERNAL_OBJECTS =

diferentiator: CMakeFiles/diferentiator.dir/main.cpp.o
diferentiator: CMakeFiles/diferentiator.dir/differentiator_tree/expression_parser.cpp.o
diferentiator: CMakeFiles/diferentiator.dir/containers/my_string/my_string.cpp.o
diferentiator: CMakeFiles/diferentiator.dir/containers/my_vector/my_vector.cpp.o
diferentiator: CMakeFiles/diferentiator.dir/containers/bor/bor.cpp.o
diferentiator: CMakeFiles/diferentiator.dir/containers/auto_free/auto_free.cpp.o
diferentiator: CMakeFiles/diferentiator.dir/work_with_file_functions/file_work_functions.cpp.o
diferentiator: CMakeFiles/diferentiator.dir/differentiator_tree/expression_tree.cpp.o
diferentiator: CMakeFiles/diferentiator.dir/differentiator_tree/tree_dfs.cpp.o
diferentiator: CMakeFiles/diferentiator.dir/build.make
diferentiator: CMakeFiles/diferentiator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oleg/Public/Oleg/course_2/ded/differentiator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable diferentiator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/diferentiator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/diferentiator.dir/build: diferentiator

.PHONY : CMakeFiles/diferentiator.dir/build

CMakeFiles/diferentiator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/diferentiator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/diferentiator.dir/clean

CMakeFiles/diferentiator.dir/depend:
	cd /home/oleg/Public/Oleg/course_2/ded/differentiator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oleg/Public/Oleg/course_2/ded/differentiator /home/oleg/Public/Oleg/course_2/ded/differentiator /home/oleg/Public/Oleg/course_2/ded/differentiator /home/oleg/Public/Oleg/course_2/ded/differentiator /home/oleg/Public/Oleg/course_2/ded/differentiator/CMakeFiles/diferentiator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/diferentiator.dir/depend

