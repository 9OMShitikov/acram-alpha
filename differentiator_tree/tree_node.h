//
// Created by oleg on 27.05.2020.
//

#ifndef DIFFERENTIATOR_TREE_NODE_H
#define DIFFERENTIATOR_TREE_NODE_H

const int MAX_NAME_SIZE = 100;

enum node_types {
    empty_node = 0,
    function_node = 1,
    variable_node = 2,
    constant_node = 3,
    operator_node = 4
};

struct tree_node {
    node_types type;
    int index;
    int first_link;
    int second_link;
    double value;
    tree_node():
            type(node_types(0)),
            index(0),
            first_link(0),
            second_link(0),
            value(0) {
    }
    tree_node(node_types type_, int index_, int first_link_, int second_link_, double value_):
            type(type_),
            index(index_),
            first_link(first_link_),
            second_link(second_link_),
            value(value_) {
    }
    tree_node(double value_):
            type(constant_node),
            index(-1),
            first_link(-1),
            second_link(-1),
            value(value_) {
    }
    ~tree_node() = default;

};

#endif //DIFFERENTIATOR_TREE_NODE_H
