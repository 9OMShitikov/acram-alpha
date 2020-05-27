#include "bor.h"

Bor::Bor() {
    size_ = 0;
    zero_node_ = new bor_node;
}
Bor::~Bor() {
    delete(zero_node_);
}

[[nodiscard]] size_t Bor::get_size() const {
    return size_;
}
int Bor::add (const char* str, int value) {
    size_++;
    ASSERT(str);
    bor_node* cur_node = zero_node_;
    int i = 0;
    while (str[i] != '\0' && str[i] != ':') {
        ASSERT(str[i] >= 0);
        if (cur_node->nodes[str[i]] == nullptr) {
            cur_node->nodes[str[i]] = new bor_node;
        }
        cur_node = cur_node->nodes[str[i]];
        ++i;
    }
    cur_node->value = value;
    return size_;
}
int Bor::check (const char* str) {
    ASSERT(str);
    bor_node* cur_node = zero_node_;
    int i = 0;
    while (str[i] != '\0' && str[i] != ':') {
        ASSERT(str[i] >= 0);
        if (cur_node->nodes[str[i]] == nullptr) {
            return -1;
        }
        cur_node = cur_node->nodes[str[i]];
        ++i;
    }
    return cur_node -> value;
}

int Bor::check_max (const char* str) {
    ASSERT(str);
    ASSERT(str);
    bor_node* cur_node = zero_node_;
    int i = 0;
    int val = -1;
    while (str[i] != '\0' && str[i] != ':') {
        ASSERT(str[i] >= 0);
        if (cur_node->nodes[str[i]] == nullptr) {
            return val;
        }
        cur_node = cur_node->nodes[str[i]];
        if (cur_node -> value != -1) val = cur_node -> value;
        ++i;
    }
    return val;
}