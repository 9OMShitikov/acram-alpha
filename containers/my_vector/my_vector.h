#ifndef DIFFERENTIATOR_MY_VECTOR_H
#define DIFFERENTIATOR_MY_VECTOR_H

#include <cstdint>
#include <iostream>

#define DEBUG false
#define CHECK if (DEBUG && check()) dump(check(), __FILE__, __LINE__, __FUNCTION__);

template <typename T>
class my_vector {
private:
    enum my_vector_err_code {
        ok = 0,
        sizes_broken = 1,
        buff_broken = 2,
        buff_pointer_broken = 3
    };

    struct stack_buffer {
        int first_canary;
        int buff_size_copy;
        int size_copy;
        int hsh;
        int size;
        int buff_size;
        T buff[1];
    };

    int first_canary_;
    stack_buffer* buff_;
    int second_canary_;

    int* second_canary_ptr () {
        return reinterpret_cast<int*> (reinterpret_cast<char*>(buff_) +
                                       4*6 + sizeof(T) * buff_->buff_size + 1);
    }

    void dump (int err_code, const char file[], int line, const char function[]) {
        std::cerr<<"Problem!!! From "<<file<<", line "<<line<<", "<<function<<std::endl;
        std::cerr<<"Problem in my_stack<T> where T = ";
        const char* str = typeid(T).name();
        int pos = 0;
        while ('0' <= str[pos] && str[pos] <= '9') ++pos;
        std::cerr<<str + pos;
        std::cerr<<std::endl;

        if (err_code == buff_pointer_broken) {
            std::cerr<<"Buffer pointer is broken"<<std::endl;
            std::cerr<<"First canary = "<<first_canary_;
            if (first_canary_ == 265) std::cerr<<"(alive)."<<std::endl;
            else std::cerr<<"(dead)."<<std::endl;
            std::cerr<<"Second canary = "<<second_canary_;
            if (second_canary_ == 265) std::cerr<<"(alive)."<<std::endl;
            else std::cerr<<"(dead)."<<std::endl;
            std::cerr<<"Buffer pointer is "<<buff_<<std::endl;
        }
        else if (err_code == sizes_broken) {
            std::cerr<<"Sizes are broken"<<std::endl;
            std::cerr<<"First buff canary = "<<buff_->first_canary;
            if (buff_->first_canary == 265) std::cerr<<"(alive)."<<std::endl;
            else std::cerr<<"(dead)."<<std::endl;
            std::cerr<<"Second buff canary = "<<*(reinterpret_cast<int*>(buff_) +
                4 * 6 + 4 + buff_->buff_size * sizeof(T));
            if (*second_canary_ptr() == 265) std::cerr<<"(alive)."<<std::endl;
            else std::cerr<<"(dead)."<<std::endl;
            std::cerr<<"Buffer pointer is "<<buff_<<std::endl;
            std::cerr<<"size values:"<<std::endl;
            std::cerr<<buff_->size<<"(original) "<<buff_->size_copy<<"(copy)"<<std::endl;
            std::cerr<<"buff_size values:"<<std::endl;
            std::cerr<<buff_->buff_size<<"(original) "<<buff_->buff_size_copy<<"(copy)"<<std::endl;
        }
        else if (err_code == buff_broken) {
            std::cerr<<"Buff is broken"<<std::endl;
            std::cerr<<"First buff canary = "<<buff_->first_canary;
            if (buff_->first_canary == 265) std::cerr<<"(alive)."<<std::endl;
            else std::cerr<<"(dead)."<<std::endl;
            std::cerr<<"Second buff canary = "<<*(reinterpret_cast<int*>(buff_) +
                4 * 6 + 1+ 4 + buff_->buff_size * sizeof(T));
            if (*second_canary_ptr() == 265) std::cerr<<"(alive)."<<std::endl;
            else std::cerr<<"(dead)."<<std::endl;
            std::cerr<<"Buffer pointer is "<<buff_<<std::endl;
            std::cerr<<"size value:"<<std::endl;
            std::cerr<<buff_->size<<std::endl;
            std::cerr<<"buff_size value:"<<std::endl;
            std::cerr<<buff_->buff_size<<std::endl;
            std::cerr<<"Buffer:"<<std::endl;
            for (int i = 0; i < buff_->buff_size; ++i) {
                if (i < buff_->size) std::cerr<<"*";
                std::cerr<<"buff["<<i<<"] = "<<std::endl;
            }
        }
        else std::cerr<<"Unknown error"<<std::endl;
        throw std::exception();
    }

    my_vector_err_code check() {
        if (first_canary_ != 265 || second_canary_ != 265 || (!buff_))
            return buff_pointer_broken;
        if (buff_->size != buff_->size_copy || buff_->buff_size != buff_->buff_size_copy)
            return sizes_broken;
        if (buff_->size < 0 || buff_->buff_size <= 0 || buff_->size > buff_->buff_size)
            return sizes_broken;
        if (buff_->first_canary != 265 ||
            *second_canary_ptr() != 265)
        {
            return buff_broken;
        }
        return ok;
    }

public:
    my_vector():
            first_canary_(265),
            second_canary_(265) {
        buff_ = (stack_buffer*) calloc(4 * 6 + 1 + 4 + 10 * sizeof(T), 1);
        buff_ -> first_canary = 265;
        buff_ -> buff_size = 10;
        buff_ -> size = 0;
        buff_ -> buff_size_copy = buff_->buff_size;
        *second_canary_ptr() = 265;
    }

    ~my_vector() {
        CHECK
        free(buff_);
    }

    void push_back(T elem) {
        CHECK
        if (buff_->size == buff_->buff_size) {
            buff_->buff_size *= 2;
            buff_ = (stack_buffer*) realloc(buff_, 4 * 6 + 1 + 4 + buff_->buff_size * sizeof(T));
            *second_canary_ptr() = 265;
        }
        buff_->buff[buff_->size] = elem;
        buff_->size++;
        buff_ -> buff_size_copy = buff_->buff_size;
        buff_ -> size_copy = buff_->size;
        CHECK
    }

    bool pop_back() {
        CHECK
        if (buff_->size <= 0) return false;
        buff_->size--;
        buff_->buff[buff_->size].~T();
        if (buff_->size * 2 >= 4 && buff_->size * 4 < buff_->buff_size) {
            buff_->buff_size = buff_->size * 2;
            buff_ = (stack_buffer*) realloc(buff_, 4 * 6 + 1 + 4 + buff_->buff_size * sizeof(T));
            *second_canary_ptr() = 265;
        }
        buff_ -> buff_size_copy = buff_->buff_size;
        buff_ -> size_copy = buff_->size;
        CHECK
        return true;
    }

    void clear() {
        CHECK
        for (int i = 0; i < buff_->size; ++i) {
            buff_->buff[i].~T();
        }
        buff_ = (stack_buffer*) calloc(4 * 6 + 1 + 4 + 10 * sizeof(T), 1);
        buff_ -> first_canary = 265;
        buff_ -> buff_size = 10;
        buff_ -> size = 0;
        buff_ -> buff_size_copy = buff_->buff_size;
        *second_canary_ptr() = 265;
    }

    T& back() {
        CHECK
        if (buff_->size <= 0) return 0;
        return buff_->buff[buff_->size - 1];
    }

    size_t size() {
        CHECK
        return buff_->size;

    }

    T& operator [] (size_t index) {
        ASSERT(index < size());

        return buff_->buff[index];
    }

    T* data() {
        CHECK
        return buff_->buff;
    }
};


#endif //DIFFERENTIATOR_MY_VECTOR_H
