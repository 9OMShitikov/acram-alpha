cmake_minimum_required(VERSION 3.10)

project(differentiator)
set(CMAKE_CXX_STANDARD 17)
include_directories("containers")
add_executable(diferentiator main.cpp
        differentiator_tree/expression_parser.h differentiator_tree/expression_parser.cpp
        asserts/my_assert.h
        containers/my_string/my_string.h containers/my_string/my_string.cpp
        containers/my_vector/my_vector.h containers/my_vector/my_vector.cpp
        containers/bor/bor.h containers/bor/bor.cpp
        containers/auto_free/auto_free.h containers/auto_free/auto_free.cpp
        work_with_file_functions/file_work_functons.h work_with_file_functions/file_work_functions.cpp

        differentiator_tree/info.h
        differentiator_tree/expression_tree.h differentiator_tree/expression_tree.cpp
                                              differentiator_tree/tree_dfs.cpp)