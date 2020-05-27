#ifndef DIFFERENTIATOR_AUTO_FREE_H
#define DIFFERENTIATOR_AUTO_FREE_H


template <class T>
class AutoFree {
public:
    AutoFree() {
        ptr = nullptr;
    }
    ~AutoFree() {
        if (ptr != nullptr)
            free(ptr);
    }
    T* get_ptr() {
        return ptr;
    }
    AutoFree(const AutoFree&) =  delete;
    void operator=(const AutoFree&) = delete;

    T* ptr;
};

#endif //DIFFERENTIATOR_AUTO_FREE_H
