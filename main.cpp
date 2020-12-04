#include <cmath>
#include "containers/auto_free/auto_free.h"
#include "containers/my_string/my_string.h"

#include "differentiator_tree/expression_tree.h"


int main(int args, char* argv[]) {
    AutoFree<char> buff;
    const char* input_file;
    const char* output_file;

    if (args <= 1) input_file = "input.txt";
    else input_file = argv[1];

    if (args <= 2) output_file = "differentiated.tex";
    else output_file = argv[2];

    int expr_size = read_string_with_free_place(&buff, input_file, 2);

    ExpressionTree my_tree;
    my_tree.read_tree(buff, expr_size);

    MyString latex_string("\\documentclass{article}\n\
\\usepackage[utf8]{inputenc}\n\
\\usepackage[T2A]{fontenc}\n\
\\usepackage[russian,english]{babel}\n\
\\usepackage{amssymb,amsmath,amsthm}\n\
\\begin{document}\n\
\\par Derivatives\n\
\\begin{gather*}\n");
    for (int i = 0; i < my_tree.variables_count; ++i) {
        ExpressionTree diff_tree;
        diff_tree.copy_tree(my_tree);
        latex_string.add_string("F_{");
        latex_string.add_string(my_tree.variables.ptr[i].name);
        latex_string.add_string("} = ");

        diff_tree.differentiate_tree(i);
        diff_tree.simplify_tree();

        diff_tree.print_latex_tree(latex_string);
        latex_string.add_string("\\\\\n");
    }
    latex_string.add_string("\\end{gather*}\n\
\\end{document}\n");
    print_buff(latex_string, output_file);
    MyString query("pdflatex ");
    query.add_string(output_file);
    system(query.data());
    return 0;
}
