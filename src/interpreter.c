
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../include/interpreter.h"
#include "../include/variable.h"
#include "../include/print.h"
#include "../include/arithmetic.h"
#include "../include/condition.h"

struct var* vars[NUMVARS];
long numvars = 0;
struct stack conditionals;

void execute_c_minus_minus(char *code) {
    long i = 0;
    long osize = 2;
    bool condition_check=false;
    conditionals.top = -1;
    char* o = (char*)(malloc(OPSIZE*sizeof(char)));
    o[0]= 'N';
    long condition_counter=0;
    while (code[i] != '\0') {
        // Check for "int" keyword
        while(code[i]==' '){
            i++;
        }
        if (strstr(&code[i], "int") == &code[i]) {
            i += 3; // Skip "int"
            i = assignment(code,i,o);
        }
        else if (strstr(&code[i], "print") == &code[i]) {
            i += 5; // Skip "print"
            i = print(code,o,i,osize);
        }
        if(strstr(&code[i], "if") == &code[i]){
            conditionals.top++;
            condition_counter++;
            condition_check=true;
            i+=2;
            long evaluated_val=0;
            while((code[i]!='{' || code[i]!=';')&&condition_check){
                while(code[i]=='(' || code[i]==' '){
                    i++;
                }
                if(isdigit(code[i])&& condition_check){
                    long value = 0;
                    char valstr[NAMESIZE];
                    long k = 0;
                    while (code[i] != ' ' && code[i] != ';' && code[i] != ')' && code[i] != '\0' && isdigit(code[i]) && condition_check) {
                        valstr[k++] = code[i++];
                    }
                    valstr[k] = '\0';
                    value = atoi(valstr);
                    if(o[0]=='N'){
                        evaluated_val = value;
                    }
                    else{
                        char op[4];
                        if(osize == 2){
                            op[0] = o[0];
                            op[1] = '\0';
                        }
                        if(osize == 3){
                            op[0] = o[0];
                            op[1] = o[1];
                            op[2] = '\0';
                        }

                        if(is_arithmetic(op)){
                            evaluated_val = perform_arithmetic(evaluated_val,op,value);
                            o[0] = 'N';
                            osize = 2; 
                        }
                        if(is_condition(op)){
                            evaluated_val = evaluate_condition(evaluated_val,op,value);
                            o[0] = 'N';
                            osize = 2;
                            
                        }

                    }
                }
                while((code[i]==' '||code[i]==')'||code[i]=='(')&&condition_check){
                    i++;
                }
                if((code[i]=='{'||code[i]=='\n')&&condition_check){
                    break;
                }
                if(isalpha(code[i])&&condition_check){
                    long num1 = 0;
                    char valstr[NAMESIZE];
                    long k = 0;
                    while (code[i] != ' ' && code[i] != ';' && code[i] != '\0' && isalpha(code[i])) {
                        valstr[k++] = code[i++];
                    }
                    valstr[k] = '\0';
                    num1 = get_variable_value(valstr);
                    if(o[0]=='N'){
                        evaluated_val = num1;
                    }
                    else{
                        char op[4];
                        if(osize == 2){
                            op[0] = o[0];
                            op[1] = '\0';
                        }
                        if(osize == 3){
                            op[0] = o[0];
                            op[1] = o[1];
                            op[2] = '\0';
                        }
                        if(is_arithmetic(op)){
                            evaluated_val = perform_arithmetic(evaluated_val,op,num1);
                            o[0] = 'N';
                            osize = 2;
                        }
                        else if(is_condition(op)){
                            evaluated_val = evaluate_condition(evaluated_val,op,num1);
                            o[0] = 'N';
                            osize = 2;
                        }
                    }
                }

                while(code[i] == ' ' || code[i]==')'){
                    i++;
                }
                if(!isdigit(code[i])&&!isalpha(code[i])){
                    char op[3];
                    long k = 0,l=i;
                    for(;code[l]!=' '&&!isdigit(code[i])&&!isalpha(code[i])&&k<2;k++,l++){
                        op[k]=code[l];
                    }
                    op[k]='\0';
                    osize = k+1;
                    strcpy(o,op);
                    i=l;
                    while(code[i] == ' ' || code[i]==')'){
                        i++;
                    }
                    
                }
                while(code[i] == ' ' || code[i]==')'){
                    i++;
                }
                if(code[i]=='{' || code[i]==';'){
                    condition_check=false;
                    break;
                }
            }
            conditionals.arr[conditionals.top]=evaluated_val;
            if(!evaluated_val){
                if(code[i]=='{'){
                    i++;
                    int k = condition_counter-1;
                    // printf("\n%ld\n",condition_counter);
                    while(condition_counter!=k){
                        if(code[i]=='{')condition_counter++;
                        // i++;
                        if(code[i]=='}')condition_counter--;
                        i++;
                    }
                    while(code[i]==' ')i++;
                    if(code[i]=='}'){
                        // printf("\n%ld %d\n",condition_counter,conditionals.top);
                        conditionals.top--;
                        i++;
                    }
                }
                else{
                    i+=2;
                    while(code[i]!=';'){
                        i++;
                    }
                    break;    
                }
            }
            else{
            }
            if(evaluated_val){
                i++;
            }
        }
        while(code[i]==' '){
            i++;
        }
        if (strstr(&code[i], "else") == &code[i]&&  conditionals.top!=-1 && !conditionals.arr[conditionals.top]){
            i+=4;
            // printf("elsetime%d",conditionals.top);
            // printf("\n%d\n",conditionals.arr[conditionals.top]);
            //  printf("\nno else\n");
            while(code[i]==' ')i++;
            if(code[i]=='{')i++;
            conditionals.top--;
        }
        if(strstr(&code[i], "else") == &code[i]&& (conditionals.top==-1 || conditionals.arr[conditionals.top])){
            i+=4;
            // printf("\nno else\n");
            while(code[i]==' ')i++;
            if(code[i]=='{'){
                i++;
                while(code[i]!='}'){
                    i++;
                } 
            }
            else{
                while(code[i]!=';'){
                    i++;
                }
                i++;
            }
            conditionals.top--;
        }
        // Skip the semicolon
        if (code[i] == ';' || code[i]=='}') {
            i++;
            o[0]='N';
            if(code[i]=='}'){
                conditionals.top--;
            }
        }
        if(code[i]=='\0'){
            break;
        }
    }
}
