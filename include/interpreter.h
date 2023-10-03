#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "../include/variable.h"
#include "print.h"
#include "arithmetic.h"
#include "condition.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
struct var{
    char name[16];
    long val;
};
struct stack{
    int arr[1000];
    int top;
};
extern struct var* vars[1000];
extern long numvars;
extern struct stack op_stack;
extern int osize;
void execute_c_minus_minus(char *code);
#endif /* INTERPRETER_H */
