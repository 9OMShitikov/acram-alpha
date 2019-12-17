//
// Created by oleg on 16.12.2019.
//

#ifndef DIFFERENTIATOR_INFO_H

enum operators {
    SUM,
    SUB,
    MUL,
    DIV
};

class operators_definitions {
public:
    const static int operators_count = 4;
    char operators_names [operators_count] [10];
    char operators_differentials [operators_count] [128];
    bor operators_bor;

    operators_definitions() {
        strcpy(operators_names[SUM], "+");
        strcpy(operators_differentials[SUM], "dx1 + dx2");
        operators_bor.add("+", SUM);

        strcpy(operators_names[SUB], "-");
        strcpy(operators_differentials[SUB], "dx1 - dx2");
        operators_bor.add("-", SUB);

        strcpy(operators_names[MUL], "*");
        strcpy(operators_differentials[MUL], "(x2*dx1) + (x1*dx2)");
        operators_bor.add("*", MUL);

        strcpy(operators_names[DIV], "/");
        strcpy(operators_differentials[DIV], "((x2*dx1) - (x1*dx2))/(x2*x2)");
        operators_bor.add("/", DIV);
    }

    double compute(operators op, double x1, double x2) {
        switch (op) {
            case SUM: return x1 + x2;
            case SUB: return x1 - x2;
            case MUL: return x1 * x2;
            case DIV: return x1 / x2;
        }
    }
};

enum functions {
    SIN,
    COS,
    TAN,
    SQRT,
};

class functions_definitions {
public:
    const static int functions_count = 4;
    char functions_names [functions_count] [10];
    char function_differentials [functions_count] [128];
    bor functions_bor;

    functions_definitions() {
        strcpy(functions_names[SIN], "sin");
        strcpy(function_differentials[SIN], "cos(x) * dx");
        functions_bor.add("sin", SIN);

        strcpy(functions_names[COS], "cos");
        strcpy(function_differentials[COS], "((-1) * sin(x)) * dx");
        functions_bor.add("cos", COS);

        strcpy(functions_names[TAN], "tan");
        strcpy(function_differentials[TAN], "(1 / (cos(x) * cos(x))) * dx");
        functions_bor.add("tan", TAN);

        strcpy(functions_names[SQRT], "sqrt");
        strcpy(function_differentials[SQRT], "(1 / (2 * sqrt(x))) * dx");
        functions_bor.add("sqrt", SQRT);
    }

    double compute(functions op, double arg) {
        switch (op) {
            case SIN: return sin(arg);
            case COS: return cos(arg);
            case TAN: return tan(arg);
            case SQRT: return sqrt(arg);
        }
    }
};
#define DIFFERENTIATOR_INFO_H
#endif //DIFFERENTIATOR_INFO_H
