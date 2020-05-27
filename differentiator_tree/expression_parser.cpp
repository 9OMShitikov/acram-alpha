#include "expression_parser.h"

int read_positive_int (const char* start, int& value) {
    int pos = 0;
    value = 0;
    if (start[pos] < '0' || start[pos] > '9') return -1;
    while (start[pos] >= '0' && start[pos] <= '9') {
        value = value*10 + start[pos] - '0';
        pos++;
    }
    return pos;
}

int read_int (const char* start, int& value) {
    int pos = 0;
    value = 0;
    if (start[0] == '-') {
        pos = 1;
        int readed = read_positive_int(start + pos, value);
        if (readed == -1) return -1;
        value = - value;
        return readed + 1;
    }
    else {
        int readed = read_positive_int(start, value);
        if (readed == -1) return -1;
        return readed;
    }
}

int read_double (const char* start,
                 my_vector<tree_node>& tree,
                 int start_pos) {
    double value = 0;
    int pos = 0;
    while (start[pos] == ' ') pos++;
    int mul = 1;
    if (start[0] == '-') {
        pos = 1;
        mul = -1;
    }
    int first_part = 0;
    int readed = read_positive_int(start + pos, first_part);
    if (readed == -1) return -1;
    if (start[pos + readed] == '.') {
        int second_part = 0;
        int second_readed = read_positive_int(start + pos + readed + 1, second_part);
        if (second_readed == -1) return -1;
        value = second_part;
        for (int i = 0; i < second_readed; ++i) value /= 10;
        value += first_part;
        value *= mul;
        pos = readed + second_readed + pos + 1;
        while (start[pos] == ' ') pos++;
        tree[start_pos] = tree_node(constant_node, 0, -1, -1, value);
        return pos;
    }
    else {
        value = first_part * mul;
        pos = readed + pos;
        while (start[pos] == ' ') pos++;
        tree[start_pos] = tree_node(constant_node, 0, -1, -1, value);
        return pos;
    }
}

int read_unit(const char* start,
              operators_definitions& op_defs,
              functions_definitions& func_defs,
              Bor& variables_bor,
              char** variables_names,
              my_vector<tree_node>& tree,
              int start_pos);

int read_simple_expression(const char* start,
                           operators_definitions& op_defs,
                           functions_definitions& func_defs,
                           Bor& variables_bor,
                           char** variables_names,
                           my_vector<tree_node>& tree,
                           int start_pos) {
    int pos = 0;
    double first = 0, second = 0;
    int first_node = start_pos;
    int f_l = read_unit(
            start + pos,
            op_defs, func_defs,
            variables_bor,
            variables_names,
            tree,
            first_node
    );
    if (f_l == -1) return -1;
    int ans = op_defs.operators_bor.check_max(start + f_l);
    if (ans == -1) {
        return f_l;
    }
    first_node = tree.size();
    tree.push_back(tree[start_pos]);
    int op_l = strlen(op_defs.operators_names[ans]);

    int second_node = tree.size();
    tree.push_back(tree_node());
    int s_l = read_unit(
            start + pos + op_l + f_l,
            op_defs,
            func_defs,
            variables_bor,
            variables_names,
            tree,
            second_node
    );
    if (s_l == -1) return -1;
    tree[start_pos] = tree_node(operator_node, ans, first_node, second_node, 0);
    return f_l + s_l + op_l;
}

int read_func(const char* start,
              operators_definitions& op_defs,
              functions_definitions& func_defs,
              Bor& variables_bor,
              char** variables_names,
              my_vector<tree_node>& tree,
              int start_pos) {
    int pos = 0;
    while (start[pos] == ' ') pos++;
    int cur_func = func_defs.functions_bor.check_max(start + pos);
    if (cur_func == -1) {
        return -1;
    }

    pos += strlen(func_defs.functions_names[cur_func]);
    while (start[pos] == ' ') pos++;
    if (start[pos] != '(') return -1;
    pos += 1;
    int link = tree.size();
    tree.push_back(tree_node());
    int exprlen = read_simple_expression(
            start + pos,
            op_defs,
            func_defs,
            variables_bor,
            variables_names,
            tree,
            link
    );
    if (exprlen == -1) {
        return -1;
    }
    pos += exprlen;
    while (start[pos] == ' ') pos++;
    if (start[pos] != ')') return -1;
    pos++;
    while (start[pos] == ' ') pos++;
    tree[start_pos] = tree_node(function_node, cur_func, link, -1, 0);
    return pos;
}

int read_var(const char* start,
             operators_definitions& op_defs,
             functions_definitions& func_defs,
             Bor& variables_bor,
             char** variables_names,
             my_vector<tree_node>& tree,
             int start_pos) {
    int pos = 0;
    while (start[pos] == ' ') pos++;
    if (start[pos] < 'a' || start[pos] > 'z') return -1;
    int length = 0;
    while ((start[length + pos] >= 'a' && start[length + pos] <= 'z') ||
           (start[length + pos] >= '0' && start[length + pos] <= '9')){
        length++;
    }
    if (length > 99) return -1;
    char str[MAX_NAME_SIZE];
    strncpy(str, start + pos, length);
    str[length] = '\0';
    int ans = variables_bor.check(str);
    if (ans == -1) {
        ans = variables_bor.get_size();
        variables_bor.add(str, ans);
        strcpy(variables_names[ans], str);
    }
    tree[start_pos] = tree_node(variable_node, ans, -1, -1, 0);
    pos += length;
    while (start[pos] == ' ')
        pos++;
    tree.size();
    return pos;
}

int read_unit(const char* start,
              operators_definitions& op_defs,
              functions_definitions& func_defs,
              Bor& variables_bor,
              char** variables_names,
              my_vector<tree_node>& tree,
              int start_pos) {
    tree.size();
    int pos = 0;
    while (start[pos] == ' ') pos++;
    if (start[pos] == '(') {
        pos++;
        int readed = read_simple_expression(
                start + pos,
                op_defs,
                func_defs,
                variables_bor,
                variables_names,
                tree,
                start_pos);
        if (readed == -1) return -1;
        pos += readed;
        while (start[pos] == ' ') pos++;
        if (start[pos] != ')') return -1;
        pos++;
        while (start[pos] == ' ') pos++;
        return pos;
    }
    else if ((start[pos] >= '0' && start[pos] <= '9') || start[pos] == '-'){
        return read_double(start, tree, start_pos);
    }
    else {
        double val = 0;
        int func_len = read_func(
                start,
                op_defs,
                func_defs,
                variables_bor,
                variables_names,
                tree,
                start_pos);
        if (func_len == -1) {
            int var_index;
            func_len = read_var(
                    start,
                    op_defs,
                    func_defs,
                    variables_bor,
                    variables_names,
                    tree,
                    start_pos);
        }
        return func_len;
    }
}

