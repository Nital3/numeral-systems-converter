// calculator function to converting

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "conversion_functions.h"


//global variables to pass data between functions   
char binary_char[33];
char octal_char[12];
char decimal_char[11];
char hexadecimal_char[9];


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

    long final_decimal_long = 0;
    char minus = ' ';

    //get binary sign
    char sgnd_char = '0';
    memcpy(&sgnd_char,argv[3],1);
    int sgnd = char_to_long(sgnd_char);
    
    switch (data_type)
    {
    case 1:
        //Binary to decimal convertion
        //Max binary lenght: 32 digits
        long binary_long[33];
        strcpy(binary_char,argv[1]);

        //geting rid of stuff left in memory 
        binary_long[0] = 0;

        //minus sign for returning 
        if(sgnd == 1 && binary_char[0] == '1') {memcpy(&minus, "-", 1);}

        //converting character binary table into long binary table
        for(int i=sgnd; i<strlen(binary_char); i++){
            binary_long[i] = char_to_long(binary_char[i]);
        }

        //converting binary long table into single decimal long
        final_decimal_long = nsys_to_decimal(binary_long, strlen(binary_char), 2);
        break;

    case 2:
        //Octal tp decimal conversion
        //Max Octal lenght: 11
        long octal_long[12];
        strcpy(octal_char,argv[1]);
    
        //converting character octal table into long octal table
        for(int i=0; i<strlen(octal_char); i++){
            octal_long[i] = char_to_long(octal_char[i]);
        }

        //converting octal long table into single decimal long
        final_decimal_long = nsys_to_decimal(octal_long, strlen(octal_char), 8);
        break;

    case 3:
        //decimal char to long conversion
        //Max decimal lenght: 10
        long decimal_long[11];
        strcpy(decimal_char,argv[1]);
    
        //converting character decimal table into long decimal table
        for(int i=0; i<strlen(decimal_char); i++){
            decimal_long[i] = char_to_long(decimal_char[i]);
        }

        //converting decimal long table into single decimal long
        for(int i=0; i<strlen(decimal_char); i++){
            final_decimal_long = final_decimal_long*10 + decimal_long[i];
        }
        break;

    case 4:
        //Hexadecimal to decimal conversion
        //Max Hex lenght: 8
        long hexadecimal_long[9];
        strcpy(hexadecimal_char,argv[1]);
    
        //converting character hexadecimal table into long hexadecimal table
        for(int i=0; i<strlen(hexadecimal_char); i++){
            hexadecimal_long[i] = char_to_long(hexadecimal_char[i]);
        }

        //converting hexadecimal long table into single decimal long
        final_decimal_long = nsys_to_decimal(hexadecimal_long, strlen(hexadecimal_char), 16);
        break;

    default:
        break;
    }



    //returning resault to PHP trought printf
    switch (data_type)
    {
    case 1:
        
        printf("%s\n", binary_char);

        decimal_to_nsys(final_decimal_long, octal_char, 12, 8, true);
        printf("%c%s\n", minus, octal_char);

        decimal_to_nsys(final_decimal_long, decimal_char, 11, 10, true);
        printf("%c%s\n", minus, decimal_char);

        decimal_to_nsys(final_decimal_long, hexadecimal_char, 9, 16, true);
        printf("%c%s\n", minus, hexadecimal_char);
        break;

    case 2:
        
        decimal_to_nsys(final_decimal_long, binary_char, 33, 2, true);
        printf("%s\n", binary_char);

        printf("%c%s\n", minus, octal_char);

        decimal_to_nsys(final_decimal_long, decimal_char, 11, 10, true);
        printf("%c%s\n", minus, decimal_char);

        decimal_to_nsys(final_decimal_long, hexadecimal_char, 9, 16, true);
        printf("%c%s\n", minus, hexadecimal_char);
        break;

    case 3:
        
        decimal_to_nsys(final_decimal_long, binary_char, 33, 2, true);
        printf("%s\n", binary_char);

        decimal_to_nsys(final_decimal_long, octal_char, 12, 8, true);
        printf("%c%s\n", minus, octal_char);

        printf("%c%s\n", minus, decimal_char);

        decimal_to_nsys(final_decimal_long, hexadecimal_char, 9, 16, true);
        printf("%c%s\n", minus, hexadecimal_char);
        break;

    case 4:
        
        decimal_to_nsys(final_decimal_long, binary_char, 33, 2, true);
        printf("%s\n", binary_char);

        decimal_to_nsys(final_decimal_long, octal_char, 12, 8, true);
        printf("%c %s\n", minus, octal_char);

        decimal_to_nsys(final_decimal_long, decimal_char, 11, 10, true);
        printf("%c %s\n", minus, decimal_char);

        printf("%c %s\n", minus, hexadecimal_char);
        break;
    
    default:
        break;
    }

}


//todo
//optimize code
//add signed binary option
//make GUI look good