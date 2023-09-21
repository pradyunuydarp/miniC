#include "../include/interpreter.h"

bool is_condition(char* op){
    bool verdict = false;
    if(!strcmp(op,"==") ||!strcmp(op,">") || !strcmp(op,"<") || !strcmp(op,">=") || !strcmp(op,"<=")|| !strcmp(op,"!=") ||!strcmp(op,"^")||!strcmp(op,"&&")||!strcmp(op,"||")||!strcmp(op,"&")||!strcmp(op,"|")){
        verdict = true;
    }
    return verdict;
}
bool evaluate_condition(long x, char *op, long y){
    if(!strcmp(op,"==")){
        return x==y;
    }
    if(!strcmp(op,"!=")){
        return x!=y;
    }
    if(!strcmp(op,">")){
        return x>y;
    }
    if(!strcmp(op,"<")){
        return x<y;
    }
    if(!strcmp(op,">=")){
        return x>=y;
    }
    if(!strcmp(op,"<=")){
        return x<=y;
    }
    if(!strcmp(op,"&&")){
        return x&&y;
    }
    if(!strcmp(op,"||")){
        return x||y;
    }
    if(!strcmp(op,"&")){
        return x&y;
    }
    if(!strcmp(op,"|")){
        return x|y;
    }
    if(!strcmp(op,"^")){
        return x^y;
    }
    return false;
}