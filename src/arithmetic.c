#include "../include/interpreter.h"
#include <stdbool.h>
bool is_arithmetic(char* op){
    bool verdict = false;
    if(!strcmp(op,"+") ||!strcmp(op,"-") || !strcmp(op,"*") || !strcmp(op,"/") || !strcmp(op,"%")|| !strcmp(op,"^")){
        verdict = true;
    }
    return verdict;
}
long perform_arithmetic(long x, char *op, long y){
    if(!strcmp(op,"+")){
        return x+y;
    }
    if(!strcmp(op,"-")){
        return x-y;
    }
    if(!strcmp(op,"*")){
        return x*y;
    }
    if(!strcmp(op,"/")){
        return x/y;
    }
    if(!strcmp(op,"%")){
        return x%y;
    }
    if(!strcmp(op,"**")){
        return pow(x,y);
    }
   return -1; 
}
