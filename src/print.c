#include "../include/interpreter.h"

void print_variable(char *token){

    // printf("%s",token);
    // if(token[0]=="){

    // }
    // char name[10];
    // int j = 0;
    // for(; token[j]!=' '; j++){
    //     name[j]=token[j];
    // }
    // name[j+1]='\0';
    for(int i = 0; i<numvars; i++){ 
        if(!strcmp(vars[i]->name,token)){
            printf("%ld\n",vars[i]->val);
        }
    }
}