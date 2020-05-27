#include "expression_tree.h"
void ExpressionTree::generate_tree(int& new_variables_count, int& new_nodes_count,
                   tree_node* new_tree_nodes, variable* new_variables) {
    if (new_variables_count > 0) ASSERT(new_variables);
    if (new_nodes_count > 0) ASSERT(new_tree_nodes);
    variables_count = new_variables_count;
    nodes_count = new_nodes_count;
    tree_.ptr = new char[sizeof(int) + variables_count * sizeof(variable) + sizeof(int) +
                         nodes_count * sizeof(tree_node)];
    variables.ptr = (reinterpret_cast<variable*> (tree_.ptr + 4));
    tree_nodes.ptr = (reinterpret_cast<tree_node*> (tree_.ptr + 4 + variables_count*sizeof(variable) + 4));

    *reinterpret_cast<int *>(tree_.ptr) = variables_count;
    memcpy(variables.ptr, new_variables, variables_count * sizeof(variable));
    *reinterpret_cast<int *>(tree_.ptr + sizeof(int) + variables_count * sizeof(variable)) = nodes_count;
    memcpy(tree_nodes.ptr, new_tree_nodes, nodes_count * sizeof(tree_node));
}

void ExpressionTree::copy_tree_nodes(int new_nodes_count, tree_node* new_tree_nodes) {
    if (new_nodes_count > 0) ASSERT(new_tree_nodes);
    nodes_count = new_nodes_count;
    void* buff = tree_.ptr;
    tree_.ptr = (char*) realloc(buff, sizeof(int) + variables_count * sizeof(variable) + sizeof(int) +
                                      nodes_count * sizeof(tree_node));
    variables.ptr = (reinterpret_cast<variable*> (tree_.ptr + 4));
    tree_nodes.ptr = (reinterpret_cast<tree_node*> (tree_.ptr + 4 + variables_count*sizeof(variable) + 4));

    *reinterpret_cast<int *>(tree_.ptr + sizeof(int) + variables_count * sizeof(variable)) = nodes_count;
    memcpy(tree_nodes.ptr, new_tree_nodes, nodes_count * sizeof(tree_node));
}

bool ExpressionTree::copy_tree(const ExpressionTree& cp_tree) {
    variables.ptr = nullptr;
    tree_nodes.ptr = nullptr;
    delete(tree_.ptr);
    variables_count = cp_tree.variables_count;
    nodes_count = cp_tree.nodes_count;
    tree_.ptr = (char*) calloc(4 + 4 + variables_count*sizeof(variable) + nodes_count*sizeof(tree_node),
                               sizeof(char));
    variables.ptr = (reinterpret_cast<variable*> (tree_.ptr + 4));
    tree_nodes.ptr = (reinterpret_cast<tree_node*> (tree_.ptr + 4 + variables_count*sizeof(variable) + 4));
    memcpy(tree_.ptr, cp_tree.tree_.ptr, 4 + 4 + variables_count*sizeof(variable) + nodes_count*sizeof(tree_node));
}

ExpressionTree::ExpressionTree(){
    tree_.ptr = nullptr;
    tree_nodes.ptr = nullptr;
    variables.ptr = nullptr;
    variables_count = 0;
    nodes_count = 0;
}

ExpressionTree::~ExpressionTree(){
    tree_nodes.ptr = nullptr;
    variables.ptr = nullptr;
    delete(tree_.ptr);
    tree_.ptr = nullptr;
}

void ExpressionTree::read_tree (AutoFree<char>& buff, int expr_size) {
    expr_size --;
    buff.get_ptr()[expr_size] = '$';
    buff.ptr[expr_size + 1] = '\0';
    Bor variables_bor;
    my_vector<tree_node> tree;
    char* variables_names[100];
    for (int i = 0; i < 100; ++i) variables_names[i] = new char[100];
    tree.push_back(tree_node());
    int s = read_simple_expression (buff.ptr, op_defs, func_defs, variables_bor,  variables_names, tree, 0);
    ASSERT(s == expr_size);

    int nodes_count = tree.size();
    int variables_count = variables_bor.get_size();
    variable* variables = new variable [variables_count];
    for (int i = 0; i < variables_count; ++i) {
        strcpy(variables[i].name, variables_names[i]);
    }

    generate_tree(variables_count, nodes_count, tree.data(), variables);
    for (int i = 0; i < 100; ++i) delete(variables_names[i]);
}

void ExpressionTree::differentiate_tree(int k) {

    my_vector<tree_node> new_tree;
    new_tree.push_back(tree_node());

    dfs_differentiate(new_tree, 0, 0, k);

    copy_tree_nodes(new_tree.size(),  new_tree.data());
}

void ExpressionTree::simplify_tree() {
    my_vector<tree_node> new_tree;
    new_tree.push_back(tree_node());
    int f = 1;
    while (f == 1) {
        f = dfs_simplify(new_tree, 0, 0);
        copy_tree_nodes(new_tree.size(),  new_tree.data());
        new_tree.clear();
        new_tree.push_back(tree_node());
    }
}

size_t ExpressionTree::print_latex_tree (MyString& str_buff) {

    dfs_latex(0, str_buff);

    return str_buff.size();
}

int ExpressionTree::get_priority(int index) const{
    ASSERT (index >= 0);
    ASSERT(index < nodes_count);
    tree_node node = tree_nodes.ptr[index];

    if (node.type != operator_node) {
        return -1;
    }
    return op_defs.priorities[index];
}