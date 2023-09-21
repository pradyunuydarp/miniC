#include "../include/interpreter.h"

int main() {
    char code[] ={
        "print(Hey this is my first program in nuydarp)~ (I'm so excited!!)! (hey)~;"
        "int var = 8;"
        "print var%4~;"
        "print ( This is var)! var~;"
        "int y =  var/2;"
        "print (This is the value of y:)y~;" 
        "int z = 10 + y;"
        "print (z-9:)z-9~;"
        "print (Hey)~ (How are you?)~;"
        " int z = var-1;"
        "   print (z- )z~;"
        " print 7+z~;"
        "if (var||0) {"
        "    int w = 20;"
        "    int k = z - var     ;"
         "    print w~;"
         "    print (z)z~;" 
        "    print k~ ;"
        "   if (k == 0){"
        "       print (k is >0)~;"
        "       int p = 90;"
        "       print p~;"
        "           if (p+90>0) {"
        "               print (p+90!=0)~;"
        "               }" 
        "       print p+1~;"
        "   }"
        "}"
        // " int u = 8;"
        // "print u~;"
        "else{"
            "print z~;"
             "print (yuyu)z+8~;"
              "print var/9~! y~;"
        "}"
        "int u  = 8;"
        // "print(u is)u~;"
        // "if(u ==8){"
            // "print 78~;"
        // "}"
        // "}"
        // ";"
    };


    execute_c_minus_minus(code);
    // printf("hi");
    return 0;
}
