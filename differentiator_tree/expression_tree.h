#ifndef DIFFERENTIATOR_EXPRESSION_TREE_H
#define DIFFERENTIATOR_EXPRESSION_TREE_H
#include "info.h"

#include "../work_with_file_functions/file_work_functons.h"
#include "../containers/my_string/my_string.h"
#include "../containers/my_vector/my_vector.h"
#include "../containers/auto_free/auto_free.h"
#include "../containers/bor/bor.h"

#include "expression_parser.h"
#include "tree_node.h"

struct variable {
    char name[MAX_NAME_SIZE];
    double value;
};

class ExpressionTree {
public:
    AutoFree<tree_node> tree_nodes;
    AutoFree<variable> variables;
    int variables_count;
    int nodes_count;
    operators_definitions op_defs;
    functions_definitions func_defs;

    ExpressionTree(const ExpressionTree&) =  delete;
    void operator=(const ExpressionTree&) = delete;

     void generate_tree(int& new_variables_count, int& new_nodes_count,
                    tree_node* new_tree_nodes, variable* new_variables);

    void copy_tree_nodes(int new_nodes_count, tree_node* new_tree_nodes);

    bool copy_tree(const ExpressionTree& cp_tree);

    ExpressionTree();

    ~ExpressionTree();

    void read_tree (AutoFree<char>& buff, int expr_size);

    void differentiate_tree(int k);

    void simplify_tree();
    size_t print_latex_tree (MyString& str_buff);

private:
    int dfs_find (int cur_node, int k);
    int dfs_count (int cur_node, double& value);
    int dfs_latex (int cur_node, MyString& str_buff);
    int dfs_copy (my_vector<tree_node>& new_tree,
                  int cur_tree_node,
                  int cur_new_tree_node);

    int dfs_differentiate (my_vector<tree_node>& new_tree,
                           int cur_tree_node,
                           int cur_new_tree_node,
                           int diff_var);

    int dfs_simplify (my_vector<tree_node>& new_tree,
                                       int cur_tree_node,
                                       int cur_new_tree_node);


    AutoFree<char> tree_;
};


#endif //DIFFERENTIATOR_EXPRESSION_TREE_H
