# The miniC project                                          
Custom Syntax interpreter

1. There are header files: interpreter.h, arithmetic.h, condition.h, print.h, and variable.h in 
   include
   
2. There are source files: interpreter.c, arithmetic.c, condition.c, print.c, variable.c, and main.c in src
 
3. The main.c is where you write C-- code, inside the code[] character array
   
4. The output executable 'main' can be found in src/output

5. This project currently supports assignment, arithmetic, conditionals(if/else conditions), and a printing format.

6. You can have up to 15 alphabetic characters for your variable name

7. This project also supports nested conditions
   
8. You can use any arithmetic/conditional expressions as a condition for if/else

9. The project is space-independent(like c)- except for the keywords
   
10. There is no notion of variable scope- any variable declared anywhere above can be used anywhere below

11. Supported arithmetic operations - '+','-','*','/','%','**'

NOTE: To do any assignment(even after initialization) please specify the variable type (int)

NOTE: Syntax for conditions:


        1.  if(condition){
            //code
        }
       
        2.  if condition {
            //code
        }
        
        (if there is an else case)
        
        else{
            //code
        }

NOTE:

    1. You can only use alphabets to name variables
    2. The project does not support BODMAS, it strictly evaluates expressions from left to right with no operator preference 
    
PRINTING FORMAT:

    1. the 'print' keyword is used.
        to print a variable(say: 'x'), use:
            print x;
            
    2. to print strings, enclose them within parentheses '()'. 
        Example:
            print (Hello World!);
            
    3. to print a '\n' character(to move to the next line), use the '~' character outside the parentheses. 
        Example:
            print (Hey)~ (How are you?);
                output: 
                    Hey
                    How are you?
                    
    4. to print a '\t' character(to 'tab'), use the '!' character outside the parentheses. 
        Example:
            print (Hey)! (How are you?);
                output: 
                    Hey     How are you? 
                    
    5. You can use any number of '~' and '!' operators
    
    6. You can print the final values of arithmetic expressions as well. 
        Example:
            int x = 9;
            print x%3 ~;
                output:
                    0
RUNNING:
After modifying the Makefile(as indicated in it), you can use the 'make' command in the project's directory.
	make
You can also use this one-line command to compile and generate the executable instead of using the makefile

	gcc -Wall -Wextra -g3 (path to /src/main.c) (path to /src/interpreter.c) (path to /src/variable.c) (path to /src/print.c) (path to /src/arithmetic.c) (path to /src/condition.c) -o (path to the executable you want to generate /output/main)
