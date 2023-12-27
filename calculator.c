// calculator function to converting

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "functions.h"


//global variables to pass data between functions   
char binary_char[33];
char octal_char[12];
char decimal_char[11];
char hexadecimal_char[9];

long binary_long[33];
long octal_long[12];
long decimal_long[11];
long hexadecimal_long[9];


//main function recives starting arguments 
//argc - number of arguments passed
//argv - table of arguments, each cell contains string pointer, argv[0] == name of program
//List of argument passed from GUI:
//argv[0] = name of program
//argv[1] = value
//argv[2] = system of given number (1 - Binary, 2 - Octal, 3 - Deciamal, 4 - Hexadecimal)
//argv[3] = signed checkbox

void main(int argc, char* argv[]){

    //get input system
    char convertion = '0';
    memcpy(&convertion,argv[2],2);
    int data_type = char_to_long(convertion);

    //get binary sign
    char sgnd_char = '0';
    memcpy(&sgnd_char,argv[3],1);
    int sgnd = char_to_long(sgnd_char);

    //check binary sign
    char minus = ' ';
    char sgn_check;
    memcpy(&sgn_check, argv[1], 1);
    if(sgnd == 1 && sgn_check == '1') {memcpy(&minus, "-", 1);}



    long final_decimal_long = 0;
    
    switch (data_type)
    {
    case 1:
        strcpy(binary_char,argv[1]);
        final_decimal_long = conversion(binary_char, binary_long, 2, sgnd);
        break;

    case 2:
        strcpy(octal_char,argv[1]);
        final_decimal_long = conversion(octal_char, octal_long, 8, 0);
        break;

    case 3:
        strcpy(decimal_char,argv[1]);
        final_decimal_long = conversion(decimal_char, decimal_long, 10, 0);
        break;

    case 4:
        strcpy(hexadecimal_char,argv[1]);
        final_decimal_long = conversion(hexadecimal_char, hexadecimal_long, 16, 0);
        break;

    default:
        break;
    }
    

    //returning resault to PHP trought printf

        //skip calculating number that program got as an input
        if(data_type!=1){
        decimal_to_nsys(final_decimal_long, binary_char, 33, 2, true);}
        
        if(data_type!=2){
        decimal_to_nsys(final_decimal_long, octal_char, 12, 8, true);}
        
        if(data_type!=3){
        decimal_to_nsys(final_decimal_long, decimal_char, 11, 10, true);}
        
        if(data_type!=4){
        decimal_to_nsys(final_decimal_long, hexadecimal_char, 9, 16, true);}
        

        printf("%s\n", binary_char);
        printf("%c%s\n", minus, octal_char);
        printf("%c%s\n", minus, decimal_char);
        printf("%c%s\n", minus, hexadecimal_char);

}