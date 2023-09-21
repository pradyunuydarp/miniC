#ifndef VARIABLE_H
#define VARIABLE_H
#include "interpreter.h"
void create_variable(char *token);
void assign_variable(char *token,int val);
int get_variable_value(char *var_name);
void update_value(char *var_name,int x);
#endif /* VARIABLE_H */ 
