#include "../include/interpreter.h"
#include "../include/variable.h"
void create_variable(char *token){
    struct var* newvar = (struct var*) (malloc(sizeof(struct var)));
    strcpy(newvar->name,token);
    vars[numvars] = newvar;
    numvars++;
}
void assign_variable(char *token, int val){
    for(int i = 0; i<numvars; i++){
        if(!strcmp(vars[i]->name,token)){
            vars[i]->val = val;
            return;
        }
    }
}
int get_variable_value(char *var_name){
   for(int i = 0; i<numvars; i++){
        if(!strcmp(vars[i]->name,var_name)){
            return vars[i]->val;
        }
    } 
    return -1;
}
void update_value(char *var_name,int x){
    for(int i = 0; i<numvars; i++){
        if(!strcmp(vars[i]->name,var_name)){
            vars[i]->val = x;
        }
    } 

}
