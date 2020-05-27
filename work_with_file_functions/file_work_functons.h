#ifndef DIFFERENTIATOR_FILE_WORK_FUNCTONS_H
#define DIFFERENTIATOR_FILE_WORK_FUNCTONS_H
#include "../asserts/my_assert.h"
#include "../containers/my_string/my_string.h"
#include "../containers/my_vector/my_vector.h"
#include "../containers/auto_free/auto_free.h"
#include "../containers/bor/bor.h"

size_t read_file (AutoFree<char> *buff, const char* input_name);

void clear_output(const char *output_name);

void print_buff(size_t size, AutoFree <char> *buff, const char *output_name);

void print_buff(MyString& buff, const char *output_name);

size_t read_string_with_free_place (AutoFree<char>* buff, const char* input_name, int elems_to_reserve);

#endif //DIFFERENTIATOR_FILE_WORK_FUNCTONS_H
