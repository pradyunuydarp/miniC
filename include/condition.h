#ifndef CONDITION_H
#define CONDITION_H
#include "interpreter.h"
#include <stdbool.h>
bool is_condition(char* op);
bool evaluate_condition(long x, char *op, long y);

#endif /* CONDITION_H */
