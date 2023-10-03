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
int assignment(char* code, int p_holder,char* o){
    long val =0;
    int i = p_holder;
                long value =0;
                // Find variable name
                while (code[i] == ' ') {
                    i++;
                }
                
                char varname[16];
                long j = 0;
                while (code[i] != ' ' && code[i] != ';' && code[i] != '\0') {
                    varname[j++] = code[i++];
                }
                varname[j] = '\0';
                // Check for "=" sign
                while (code[i] == ' '&& code[i]!= ';') {
                    i++;
                }
                create_variable(varname);//create an instance
                if (code[i] == '=') {
                    i++; // Skip "="
                    // Find the value to assign
                    while (code[i] == ' ') {
                        i++;
                    }
                    while(code[i] != ';'){
                        if(isdigit(code[i])){
                            //if the expression contains a number
                            char valstr[16];
                            long k = 0;
                            while (code[i] != ' ' && code[i] != ';' && code[i] != '\0' && isdigit(code[i])) {
                                valstr[k++] = code[i++];
                            }
                            valstr[k] = '\0';
                            value = atoi(valstr);
                            // Convert the value to an integer and assign
                            if(o[0] =='N'){ 
                                val = value;
                            }
                            else{
                                //if there's a pending operation in the opstack
                                char op[2];
                                op[0] = o[0];
                                op[1] = '\0';
                                val = perform_arithmetic(val,op,value);
                                o[0] = 'N';
                            } 
                        }
                        while (code[i] == ' ') {
                                i++;
                            }
                        if(isalpha(code[i])){
                            //If that expression contains a variable
                            char probably_var[16];
                            long k = 0;
                            while (code[i] != ' ' && code[i] != ';' && code[i] != '\0' && isalpha(code[i])) {
                                probably_var[k++] = code[i++];
                            }
                            probably_var[k] = '\0';
                            long num1 = get_variable_value(probably_var);//will get the value of the variable
                            while (code[i] == ' ') {
                                i++;
                            }
                            if(o[0]=='N'){
                                val = num1;
                            }
                            if(o[0]!='N'){
                                //If there's a pending operation in the opstack
                                char op[2];
                                op[0] = o[0];
                                op[1] = '\0';
                                val = perform_arithmetic(val,op,num1);
                                o[0] = 'N';
                            }      
                        }
                        while (code[i] == ' ' && code[i]!=';') {
                            i++;
                        }          
                        if(code[i]=='+'||code[i]=='-'||code[i]=='/'||code[i]=='*'||code[i]=='%'){
                            //to add an operation to the opstack
                            if(code[i]=='*'&&code[i+1]=='*'){
                                o[0]='*';
                                o[1]='*';
                                o[2]='\0';
                                i+=2;
                            }
                            else{
                                o[0] = code[i];i++;
                            }
                        }
                        while (code[i] == ' ') {
                                i++;
                            }
                         if(code[i]==';'){
                            assign_variable(varname, val);
                            break;

                        }
                }
                }
            return i;
                        
} 


                       
