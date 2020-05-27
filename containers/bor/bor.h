#ifndef DIFFERENTIATOR_BOR_H
#define DIFFERENTIATOR_BOR_H

#include "../../asserts/my_assert.h"

class Bor {
public:
    Bor();
    ~Bor();

    [[nodiscard]] size_t get_size() const;

    int add (const char* str, int value);

    int check (const char* str);

    int check_max (const char* str);

private:
    struct bor_node {
        bor_node* nodes[128];
        int value;
        bor_node() {
            for (int i = 0; i < 128; ++i)
                nodes[i] = nullptr;
            value = -1;
        }
        ~bor_node() {
            for (int i = 0; i < 128; ++i)
                if (nodes[i] != nullptr) delete(nodes[i]);
        }
    };
    size_t size_;
    bor_node* zero_node_;
};

#endif //DIFFERENTIATOR_BOR_H