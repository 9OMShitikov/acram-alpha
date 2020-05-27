
#ifndef DIFFERENTIATOR_MY_STRING_H
#define DIFFERENTIATOR_MY_STRING_H

#include <string_view>
#include <cstdio>
#include <cstring>
#include <iostream>
#include "../../asserts/my_assert.h"
class MyString {
public:
    MyString();

    explicit MyString(const char* origin);

    ~MyString();
    MyString(const MyString&) =  delete;
    void operator=(const MyString&) = delete;

    void add_string (const char* add);

    void add_int (const int add_value);

    [[nodiscard]] const char* data() const;

    [[nodiscard]] size_t size() const;

private:
    char* data_;
    size_t taken_;
    size_t size_;
};


#endif //DIFFERENTIATOR_MY_STRING_H
