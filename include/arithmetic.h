#ifndef ARITHMETIC_H
#define ARITHMETIC_H
#include <stdbool.h>
#include "interpreter.h"
bool is_arithmetic(char* op);
long perform_arithmetic(long x, char *op, long y);

#endif /* ARITHMETIC_H */
