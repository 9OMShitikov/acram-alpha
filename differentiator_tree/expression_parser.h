#ifndef DIFFERENTIATOR_EXPRESSION_PARSER_H
#define DIFFERENTIATOR_EXPRESSION_PARSER_H
#include "info.h"
#include "tree_node.h"
#include "../containers/my_string/my_string.h"
#include "../containers/my_vector/my_vector.h"
#include "../containers/auto_free/auto_free.h"
#include "../containers/bor/bor.h"


int read_positive_int (const char* start, int& value);

int read_int (const char* start, int& value);

int read_double (const char* start,
                 my_vector<tree_node>& tree,
                 int start_pos);

int read_unit(const char* start,
              operators_definitions& op_defs,
              functions_definitions& func_defs,
              Bor& variables_bor,
              char** variables_names,
              my_vector<tree_node>& tree,
              int start_pos);

int read_simple_expression (const char* start,
                            operators_definitions& op_defs,
                            functions_definitions& func_defs,
                            Bor& variables_bor,
                            char** variables_names,
                            my_vector<tree_node>& tree,
                            int start_pos);

int read_simple_expression_with_priority (const char* start,
                           operators_definitions& op_defs,
                           functions_definitions& func_defs,
                           Bor& variables_bor,
                           char** variables_names,
                           my_vector<tree_node>& tree,
                           int start_pos, int priority);

int read_func(const char* start,
              operators_definitions& op_defs,
              functions_definitions& func_defs,
              Bor& variables_bor,
              char** variables_names,
              my_vector<tree_node>& tree,
              int start_pos);

int read_var(const char* start,
             operators_definitions& op_defs,
             functions_definitions& func_defs,
             Bor& variables_bor,
             char** variables_names,
             my_vector<tree_node>& tree,
             int start_pos);

int read_unit(const char* start,
              operators_definitions& op_defs,
              functions_definitions& func_defs,
              Bor& variables_bor,
              char** variables_names,
              my_vector<tree_node>& tree,
              int start_pos);

#endif //DIFFERENTIATOR_EXPRESSION_PARSER_H
