//
// Created by oleg on 16.12.2019.
//

#ifndef DIFFERENTIATOR_INFO_H
#include "../containers/bor/bor.h"
#include <cstring>
#include <cmath>

enum operators {
    SUM,
    SUB,
    MUL,
    DIV,
    POW,
    POW1
};

class operators_definitions {
public:
    const int max_priority = 3;
    const static int operators_count = 6;
    char operators_names [operators_count] [10];
    char operators_differentials [operators_count] [128];
    size_t read_priorities [operators_count];
    size_t priorities [operators_count];
    int priorities_left [operators_count];
    int priorities_right [operators_count];
    Bor operators_bor;

    operators_definitions() {
        strcpy(operators_names[SUM], "+");
        strcpy(operators_differentials[SUM], "dx1 + dx2");
        operators_bor.add("+", SUM);
        priorities[SUM] = 4;
        priorities_left[SUM] = 4;
        priorities_right[SUM] = 4;
        read_priorities[SUM] = 3;

        strcpy(operators_names[SUB], "-");
        strcpy(operators_differentials[SUB], "dx1 - dx2");
        operators_bor.add("-", SUB);
        priorities[SUB] = 3;
        priorities_left[SUB] = 4;
        priorities_right[SUB] = 3;
        read_priorities[SUB] = 3;

        strcpy(operators_names[MUL], "*");
        strcpy(operators_differentials[MUL], "(x2*dx1) + (x1*dx2)");
        operators_bor.add("*", MUL);
        priorities[MUL] = 2;
        priorities_left[MUL] = 2;
        priorities_right[MUL] = 2;
        read_priorities[MUL] = 2;


        strcpy(operators_names[DIV], "/");
        strcpy(operators_differentials[DIV], "((x2*dx1) - (x1*dx2))/(x2*x2)");
        operators_bor.add("/", DIV);
        priorities[DIV] = 1;
        priorities_left[DIV] = 4;
        priorities_right[DIV] = 4;
        read_priorities[DIV] = 2;

        strcpy(operators_names[POW], "^");
        strcpy(operators_differentials[POW], "(x2*(x1^(x2-1))) * dx1");
        operators_bor.add("^", POW);
        priorities[POW] = 0;
        priorities_left[POW] = -1;
        priorities_right[POW] = 4;
        read_priorities[POW] = 1;

        strcpy(operators_names[POW1], "@");
        strcpy(operators_differentials[POW1], "(x1^x2) * (((x2 / x1) * dx1) + (ln(x1) * dx2))");
        operators_bor.add("@", POW1);
        priorities[POW1] = 0;
        priorities_left[POW1] = 0;
        priorities_right[POW1] = 0;
        read_priorities[POW1] = 1;
    }

    double compute(operators op, double x1, double x2) {
        switch (op) {
            case SUM: return x1 + x2;
            case SUB: return x1 - x2;
            case MUL: return x1 * x2;
            case DIV: return x1 / x2;
            case POW: return pow(x1, x2);
        }
    }
};

enum functions {
    SIN,
    COS,
    TAN,
    SQRT,
    LN,
    EXP
};

class functions_definitions {
public:
    const static int functions_count = 7;
    char functions_names [functions_count] [10];
    char function_differentials [functions_count] [128];
    Bor functions_bor;

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

        strcpy(functions_names[LN], "ln");
        strcpy(function_differentials[LN], "(1/x) * dx");
        functions_bor.add("ln", LN);

        strcpy(functions_names[EXP], "exp");
        strcpy(function_differentials[EXP], "x * dx");
        functions_bor.add("exp", EXP);
    }

    double compute(functions op, double arg) {
        switch (op) {
            case SIN: return sin(arg);
            case COS: return cos(arg);
            case TAN: return tan(arg);
            case SQRT: return sqrt(arg);
            case LN: return log(arg);
            case EXP: return exp(arg);
        }
    }
};
#define DIFFERENTIATOR_INFO_H
#endif //DIFFERENTIATOR_INFO_H
