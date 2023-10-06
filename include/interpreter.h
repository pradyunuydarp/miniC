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
#define NAMESIZE 16
#define NUMVARS 1000
#define STACKARRSIZE 1000
struct var{
    char name[NAMESIZE];
    long val;
};
struct stack{
    int arr[STACKARRSIZE];
    int top;
};
extern struct var* vars[NUMVARS];
extern long numvars;
extern struct stack op_stack;
extern int osize;
void execute_c_minus_minus(char *code);
#endif /* INTERPRETER_H */
