#include "../include/interpreter.h"
int main(){
    char *op1 = "==";
    char *op2 = "!=";
    char *op3 = "&&";
    char *op4 = "||";
    char *op5 = "&";
    char *op6 = "|";
    char *op7 = "^";
    char *op8 = ">";
    char *op9 = "<";
    char *op10 = ">=";
    char *op11 = "<+";
    printf("1==2 %d\n",evaluate_condition(1,op1,2));
    printf("1!=2 %d\n",evaluate_condition(1,op2,2));
    printf("1&&2=%d\n",evaluate_condition(1,op3,2));
    printf("1||2=%d\n",evaluate_condition(1,op4,2));
    printf("1&2=%d\n",evaluate_condition(1,op5,2));
    printf("1|2=%d\n",evaluate_condition(1,op6,2));
    printf("1^2=%d\n",evaluate_condition(1,op7,2));
    printf("1>2=%d\n",evaluate_condition(1,op8,2));
    printf("1<2=%d\n",evaluate_condition(1,op9,2));
    printf("1>=2=%d\n",evaluate_condition(1,op10,2));
    printf("1<=2=%d\n",evaluate_condition(1,op11,2));
    return 0;
    // printf(evaluate_condition(1,op1,2));

}