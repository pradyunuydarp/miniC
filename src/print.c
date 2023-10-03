#include "../include/interpreter.h"

void print_variable(char *token){
    for(int i = 0; i<numvars; i++){ 
        if(!strcmp(vars[i]->name,token)){
            printf("%ld\n",vars[i]->val);
        }
    }
}
int print(char*code, char* o, int p_holder,int osize){
    int i = p_holder;
    long val =0;
    long value =0;
    while(code[i]!=';'){ 
                // Find the variable name to print
                while (code[i] == ' ') {
                    i++;
                }
                if(code[i]=='('){
                    i++;
                    while(code[i]!=')'){
                        printf("%c",code[i]);
                        i++;
                    }
                    i++;
                }
                    if(code[i]=='~'||code[i]=='!'){
                        while(code[i]!=';'&& code[i]!=' '){
                            if(code[i]=='~'){
                                printf("\n");
                                i++;
                            } 
                            if(code[i]=='!'){
                                printf("\t");
                                i++;
                            }
                            if(code[i]==' '||code[i]=='('){
                                break;
                            }
                        }
                    }
                while (code[i] == ' ') {
                    i++;
                }
                if(code[i]==';')break;
                if(code[i]!='('){
                    while (code[i] == ' ') {
                        i++;
                    }
                    while(code[i] != ';'){
                        if(isdigit(code[i])){
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
                                if(osize==2){
                                    char op[2];
                                    op[0] = o[0];
                                    op[1] = '\0';
                                    val = perform_arithmetic(val,op,value);
                                    o[0] = 'N';
                                }
                                if(osize==3){
                                    char op[3];
                                    op[0] = o[0];
                                    op[1] = o[1]; 
                                    op[2] = '\0';
                                    val = perform_arithmetic(val,op,value);
                                    o[0] = 'N'; 
                                }
                            } 
                        }
                        while (code[i] == ' ') {
                                i++;
                            }
                        if(isalpha(code[i])){
                            char probably_var[16];
                            long k = 0;
                            while (code[i] != ' ' && code[i] != ';' && code[i] != '\0' && isalpha(code[i])) {
                                probably_var[k++] = code[i++];
                            }
                            probably_var[k] = '\0';
                            long num1 = get_variable_value(probably_var);
                            while (code[i] == ' ') {
                                i++;
                            }
                            if(o[0]=='N'){
                                val = num1;
                            }
                            if(o[0]!='N'){
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
                            if(code[i]=='*'&&code[i+1]=='*'){
                                // printf("%c%c",code[i],code[i+1]);
                                o[0]='*';
                                o[1]='*';
                                o[2]='\0';
                                osize = 3;
                                i+=2;
                            }
                            else{
                                o[0] = code[i];i++;
                                osize = 2;
                            }
                        }
                        while (code[i] == ' ') {
                                i++;
                            }
                        if(code[i]==';'||code[i]=='~'||code[i]=='!'||code[i]=='('){
                            printf("%ld",val);
                            break;
                            
                        }    

                    } 
                }
            }
            return i;
}