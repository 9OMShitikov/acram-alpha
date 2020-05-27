
#include "my_string.h"
MyString::MyString():   data_(reinterpret_cast<char*>(calloc(16, sizeof(char)))),
              size_(0),
              taken_(16) {
}

MyString::MyString(const char* origin) {
    size_ = strlen(origin);
    taken_ = size_;
    if (taken_ < 16) {
        taken_ = 16;
    }
    data_ = reinterpret_cast<char*>(calloc(taken_, sizeof(char)));
    strcpy(data_, origin);
}

MyString::~MyString() {
    free(data_);
}

void MyString::add_string (const char* add) {
    ASSERT(add);
    if (size_ + strlen(add) + 2 >= taken_) {
        taken_ += std::max(taken_, strlen(add));
        data_ = (char*) realloc(data_, taken_);
    }
    strcpy(data_ + size_, add);
    size_ += strlen(add);
}

void MyString::add_int (const int add_value) {
    char add[17];
    sprintf(add, "%d", add_value);
    add_string(add);
}

[[nodiscard]] const char* MyString::data() const {
    return data_;
}

[[nodiscard]] size_t MyString::size() const{
    return size_;
}