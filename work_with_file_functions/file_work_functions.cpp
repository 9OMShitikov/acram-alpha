#include "file_work_functons.h"
size_t read_file (AutoFree<char> *buff, const char* input_name){
    ASSERT(buff);
    ASSERT(input_name);
    FILE *input_file = nullptr;
    input_file = fopen(input_name, "r");
    ASSERT(input_file);
    ASSERT(fseek(input_file, 0L, SEEK_END) == 0);
    long size = ftell(input_file);
    ASSERT(size >= 0);
    ASSERT(fseek(input_file, 0L, SEEK_SET) == 0);
    (*buff).ptr = (char *) calloc(size + 1, sizeof(char));
    if (fread((*buff).ptr, sizeof(char), size + 1, input_file) != size + 1) {
        ASSERT(feof(input_file));
    }
    ASSERT(fclose(input_file) == 0);
    ++size;

    char *cur_buff_symbol = (*buff).ptr + (size - 2);
    while (size > 1 && *cur_buff_symbol == '\0') {
        --size;
        --cur_buff_symbol;
    }

    return size;
}


void clear_output(const char *output_name) {
    ASSERT(output_name);
    FILE *file = fopen(output_name, "w");
    ASSERT(file);
    ASSERT(fclose(file) == 0);
}

void print_buff(size_t size, AutoFree <char> *buff, const char *output_name) {
    ASSERT(buff);
    ASSERT(output_name);

    FILE *file = fopen(output_name, "a");
    ASSERT(file);

    for (int i = 0; i < size; i++) {
        if (i == 0 || (*buff).ptr[i - 1] == '\0') {
            ASSERT(fputs((*buff).ptr + i, file) != EOF);
            fputc('\n', file);
            ASSERT(!ferror(file));
        }
    }
    ASSERT(fclose(file) == 0);
}

void print_buff(MyString& buff, const char *output_name) {
    ASSERT(output_name);

    FILE *file = fopen(output_name, "w");
    ASSERT(file);

    fwrite(buff.data(), sizeof(char), buff.size(), file);
    ASSERT(!ferror(file));

    ASSERT(fclose(file) == 0);
}


size_t read_string_with_free_place (AutoFree<char> *buff, const char* input_name, int elems_to_reserve){
    ASSERT(buff);
    ASSERT(input_name);
    FILE *input_file = nullptr;
    input_file = fopen(input_name, "rb");
    ASSERT(input_file);
    ASSERT(fseek(input_file, 0L, SEEK_END) == 0);
    long size = ftell(input_file)/sizeof(char);
    ASSERT(size >= 0);
    ASSERT(fseek(input_file, 0L, SEEK_SET) == 0);
    (*buff).ptr = (char *) calloc(size + elems_to_reserve + 1, sizeof(char));
    if (fread((*buff).ptr, sizeof(char), size + 1, input_file) != size + 1) {
        ASSERT(feof(input_file));
    }
    ASSERT(fclose(input_file) == 0);

    return size;
}