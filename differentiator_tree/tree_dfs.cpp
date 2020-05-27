#include "info.h"
#include "expression_tree.h"

const double eps = 0.001;
bool is_equal_to (double a, double b) {
    return ((a - eps <= b) && (a + eps >= b));
}
bool is_zero (double a) {
    return is_equal_to(a, 0);
}

bool is_one (double a) {
    return is_equal_to(a, 1);
}

int ExpressionTree::dfs_count (int cur_node, double& value) {
    ASSERT(cur_node >= 0);
    tree_node node = tree_nodes.ptr[cur_node];
    switch (node.type) {
        case function_node: {
            ASSERT(node.index >= 0);
            ASSERT(node.first_link >= 0);
            ASSERT(node.second_link == -1);
            double first_value = 0;
            dfs_count(node.first_link, first_value);
            value = func_defs.compute(functions(node.index), first_value);
        }
            break;
        case operator_node: {
            ASSERT(node.index >= 0);
            ASSERT(node.first_link >= 0);
            ASSERT(node.second_link >= 0);
            double first_value = 0, second_value = 0;
            dfs_count(node.first_link, first_value);
            dfs_count(node.second_link, second_value);
            value = op_defs.compute(operators(node.index), first_value, second_value);
        }
            break;
        case variable_node: {
            ASSERT(node.index >= 0);
            value = variables.ptr[node.index].value;
        }
            break;
        case constant_node: {
            value = node.value;
        }
            break;
    }
    return 0;
}

int ExpressionTree::dfs_find (int cur_node,
              int k) {
    ASSERT(cur_node >= 0);
    tree_node node = tree_nodes.ptr[cur_node];
    int result = 0;
    if (node.type == variable_node)
        if (node.index == k)
            return 1;
    if (node.first_link != -1) {
        if (dfs_find(node.first_link, k))
            result = 1;
    }
    if (node.second_link != -1) {
        if (dfs_find(node.second_link, k))
            result = 1;
    }
    return result;
}

int ExpressionTree::dfs_copy (my_vector<tree_node>& new_tree,
              int cur_tree_node,
              int cur_new_tree_node) {
    tree_node node = tree_nodes.ptr[cur_tree_node];
    new_tree[cur_new_tree_node] = node;
    if (node.first_link != -1) {
        new_tree[cur_new_tree_node].first_link = new_tree.size();
        new_tree.push_back(tree_node());
        dfs_copy(new_tree, node.first_link, new_tree.size() - 1);
    }
    if (node.second_link != -1) {
        new_tree[cur_new_tree_node].second_link = new_tree.size();
        new_tree.push_back(tree_node());
        dfs_copy(new_tree, node.second_link, new_tree.size() - 1);
    }
    return 0;
}


int ExpressionTree::dfs_differentiate (my_vector<tree_node>& new_tree,
                       int cur_tree_node,
                       int cur_new_tree_node,
                       int diff_var) {
    ASSERT(cur_tree_node >= 0);
    ASSERT(cur_new_tree_node >= 0);
    tree_node node = tree_nodes.ptr[cur_tree_node];
    int last_size = new_tree.size();

    switch (node.type) {
        case function_node: {
            ASSERT(node.index >= 0);
            ASSERT(node.first_link >= 0);
            ASSERT(node.second_link == -1);
            Bor cur_bor;
            const int x = 0;
            const int dx = 1;
            cur_bor.add("x", x);
            cur_bor.add("dx", dx);
            char*temp[100];
            for (int i = 0; i < 10; ++i) {temp[i] = new char[100]; temp[i][0] = 0;}
            int res = read_simple_expression(func_defs.function_differentials[node.index],
                                             op_defs,
                                             func_defs,
                                             cur_bor,
                                             temp,
                                             new_tree,
                                             cur_new_tree_node);
            int cur_size = new_tree.size();
            for (int i = last_size; i < cur_size; ++i) {
                if(new_tree[i].type == variable_node) {
                    switch(new_tree[i].index) {
                        case x: {
                            dfs_copy(new_tree, node.first_link, i);
                        }
                            break;
                        case dx: {
                            if (!dfs_find(node.first_link, diff_var)) {
                                new_tree[i] = tree_node( 0);
                            }
                            else dfs_differentiate(new_tree, node.first_link, i, diff_var);
                        }
                            break;
                    }
                }
            }
        }
            break;
        case operator_node: {
            Bor cur_bor;
            const int x1 = 0;
            const int dx1 = 1;
            const int x2 = 2;
            const int dx2 = 3;
            cur_bor.add("x1", x1);
            cur_bor.add("dx1", dx1);
            cur_bor.add("x2", x2);
            cur_bor.add("dx2", dx2);
            char** temp = nullptr;
            if (node.index == POW) {
                if (dfs_find(node.second_link, diff_var)) {
                    node.index = POW1;
                }
            }
            int res = read_simple_expression(op_defs.operators_differentials[node.index],
                                             op_defs,
                                             func_defs,
                                             cur_bor,
                                             temp,
                                             new_tree,
                                             cur_new_tree_node);
            int cur_size = new_tree.size();
            for (int i = last_size; i < cur_size; ++i) {
                if(new_tree[i].type == variable_node) {
                    switch(new_tree[i].index) {
                        case x1: {
                            dfs_copy(new_tree, node.first_link, i);
                        }
                            break;
                        case dx1: {
                            if (!dfs_find(node.first_link, diff_var)) {
                                new_tree[i] = tree_node( 0);
                            }
                            else dfs_differentiate(new_tree, node.first_link, i, diff_var);
                        }
                            break;
                        case x2: {
                            dfs_copy(new_tree, node.second_link, i);
                        }
                            break;
                        case dx2: {
                            if (!dfs_find(node.second_link, diff_var)) {
                                new_tree[i] = tree_node( 0);
                            }
                            else dfs_differentiate(new_tree, node.second_link, i, diff_var);
                        }
                            break;
                    }
                }
            }
        }
            break;
        case variable_node: {
            ASSERT(node.index >= 0);
            if (node.index == diff_var) {
                new_tree[cur_new_tree_node] = tree_node(1);
            }
            else
                new_tree[cur_new_tree_node] = tree_node(0);
        }
            break;
        case constant_node: {
            new_tree[cur_new_tree_node] = tree_node( 0);
        }
            break;
        default:
            break;
    }
    return 0;
}

int ExpressionTree::dfs_simplify (my_vector<tree_node>& new_tree,
                  int cur_tree_node,
                  int cur_new_tree_node) {
    ASSERT(cur_tree_node >= 0);
    ASSERT(cur_new_tree_node >= 0);
    tree_node node = tree_nodes.ptr[cur_tree_node];
    int last_size = new_tree.size();
    int ret_val = 0;
    switch (node.type) {
        case function_node: {
            ASSERT(node.index >= 0);
            ASSERT(node.first_link >= 0);
            ASSERT(node.second_link == -1);
            if (tree_nodes.ptr[node.first_link].type == constant_node) {
                new_tree[cur_new_tree_node] = tree_node(
                        func_defs.compute(functions(node.index), tree_nodes.ptr[node.first_link].value));
                ret_val = 1;
            }
            else{
                new_tree[cur_new_tree_node] = node;
                new_tree[cur_new_tree_node].first_link = new_tree.size();
                new_tree.push_back(tree_node());
                if (dfs_simplify(new_tree,
                                 node.first_link,
                                 new_tree.size() - 1))
                    ret_val = 1;
            }
        }
            break;
        case operator_node: {
            bool fl = false;
            if (tree_nodes.ptr[node.first_link].type == constant_node)
            {
                if (tree_nodes.ptr[node.second_link].type == constant_node)
                {
                    new_tree[cur_new_tree_node] = tree_node(
                            op_defs.compute(operators(node.index),
                                            tree_nodes.ptr[node.first_link].value,
                                            tree_nodes.ptr[node.second_link].value));
                    fl = true;
                    ret_val = 1;
                }
                else {
                    switch (node.index) {
                        case SUM:
                        {
                            if (is_zero(tree_nodes.ptr[node.first_link].value)) {
                                dfs_simplify(new_tree,
                                             node.second_link,
                                             cur_new_tree_node);
                                fl = true;
                                ret_val = 1;
                            }
                        }
                            break;
                        case MUL:
                        {
                            if (is_one(tree_nodes.ptr[node.first_link].value)) {
                                dfs_simplify(new_tree,
                                             node.second_link,
                                             cur_new_tree_node);
                                fl = true;
                                ret_val = 1;
                            }

                            if (is_zero(tree_nodes.ptr[node.first_link].value)) {
                                new_tree[cur_new_tree_node] = tree_node(0);
                                fl = true;
                                ret_val = 1;
                            }
                        }
                            break;
                        case DIV:
                        {
                            if (is_zero(tree_nodes.ptr[node.first_link].value)) {
                                new_tree[cur_new_tree_node] = tree_node(0);
                                fl = true;
                                ret_val = 1;
                            }
                        }
                            break;
                        default:
                            break;
                    }
                }
            }
            else if (tree_nodes.ptr[node.second_link].type == constant_node) {
                switch (node.index) {
                    case SUM:
                    {
                        if (is_zero(tree_nodes.ptr[node.second_link].value)) {
                            dfs_simplify(new_tree,
                                         node.first_link,
                                         cur_new_tree_node);
                            fl = true;
                            ret_val = 1;
                        }
                    }
                        break;
                    case SUB:
                    {
                        if (is_zero(tree_nodes.ptr[node.second_link].value)) {
                            dfs_simplify(new_tree,
                                         node.first_link,
                                         cur_new_tree_node);
                            fl = true;
                            ret_val = 1;
                        }
                    }
                        break;
                    case MUL:
                    {
                        if (is_one(tree_nodes.ptr[node.second_link].value)) {
                            dfs_simplify(new_tree,
                                         node.first_link,
                                         cur_new_tree_node);
                            fl = true;
                            ret_val = 1;
                        }

                        if (is_zero(tree_nodes.ptr[node.second_link].value)) {
                            new_tree[cur_new_tree_node] = tree_node(0);
                            fl = true;
                            ret_val = 1;
                        }
                    }
                        break;
                    case DIV:
                    {
                        ASSERT(!is_zero(tree_nodes.ptr[node.second_link].value));
                    }
                        break;
                    case POW:
                    {
                        if (is_zero(tree_nodes.ptr[node.second_link].value)) {
                            new_tree[cur_new_tree_node] = tree_node(1);
                            fl = true;
                            ret_val = 1;
                        }

                        if (is_one(tree_nodes.ptr[node.second_link].value)) {
                            dfs_simplify(new_tree,
                                         node.first_link,
                                         cur_new_tree_node);
                            fl = true;
                            ret_val = 1;
                        }
                    }
                        break;
                }
            }
            if (!fl) {
                new_tree[cur_new_tree_node] = node;
                new_tree[cur_new_tree_node].first_link = new_tree.size();
                new_tree.push_back(tree_node());
                if (dfs_simplify(new_tree,
                                 node.first_link,
                                 new_tree.size() - 1))
                    ret_val = 1;
                new_tree[cur_new_tree_node].second_link = new_tree.size();
                new_tree.push_back(tree_node());
                if (dfs_simplify(new_tree,
                                 node.second_link,
                                 new_tree.size() - 1))
                    ret_val = 1;
            }
        }
            break;
        default: {
            new_tree[cur_new_tree_node] = node;
        }
    }
    return ret_val;
}

int ExpressionTree::dfs_latex (int cur_node, MyString& str_buff) {
    ASSERT(cur_node >= 0);
    tree_node node = tree_nodes.ptr[cur_node];
    switch (node.type) {
        case function_node: {
            ASSERT(node.index >= 0);
            ASSERT(node.first_link >= 0);
            ASSERT(node.second_link == -1);
            double first_value = 0;
            str_buff.add_string(func_defs.functions_names[node.index]);
            str_buff.add_string("\\left(");
            dfs_latex(node.first_link, str_buff);
            str_buff.add_string("\\right)");
        }
            break;
        case operator_node: {
            ASSERT(node.index >= 0);
            ASSERT(node.first_link >= 0);
            ASSERT(node.second_link >= 0);
            switch (node.index) {
                case DIV: {
                    str_buff.add_string(" \\frac {");
                } break;
                case POW: {}
                    break;
                default: {
                    str_buff.add_string("\\left(");
                }
            }
            dfs_latex(node.first_link, str_buff);
            switch (node.index) {
                case DIV: {
                    str_buff.add_string("} {");
                } break;
                case MUL: {
                    str_buff.add_string(" \\cdot ");
                } break;
                case SUM: {
                    str_buff.add_string(" + ");
                } break;
                case SUB: {
                    str_buff.add_string(" - ");
                } break;
                case POW: {
                    str_buff.add_string(" ^ {");
                }
            }
            dfs_latex(node.second_link, str_buff);
            switch (node.index) {
                case DIV: {
                    str_buff.add_string("}");
                } break;
                case POW: {
                    str_buff.add_string("}");
                } break;
                default: {
                    str_buff.add_string("\\right)");
                }
            }
        }
            break;
        case variable_node: {
            ASSERT(node.index >= 0);
            str_buff.add_string(variables.ptr[node.index].name);
        }
            break;
        case constant_node: {
            char c[128];
            snprintf(c, 127, "%.4g", node.value);
            str_buff.add_string(c);
        }
            break;
        default:
            break;
    }
    return 0;
}
