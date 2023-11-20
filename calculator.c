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
//argv[1] = number in binary system as table of chars
//argv[2] = number in octal system as table of chars
//argv[3] = number in decimal system as table of chars
//argv[4] = number in hexadecimal system as table of chars
int main(int argc, char* argv[]){



    //Binary to decimal convertion
    //Max binary lenght: 32 digits
    long binary_long[33];
    strcpy(binary_char,argv[1]);
    
    //converting character binary table into long binary table
    for(int i=0; i<strlen(binary_char); i++){
        binary_long[i] = char_to_long(binary_char[i]);
    }

    //converting binary long table into single decimal long
    long bdecimal_long = nsys_to_decimal(binary_long, strlen(binary_char), 2);



    //Octal tp decimal conversion
    //Max Octal lenght: 11
    long octal_long[12];
    strcpy(octal_char,argv[2]);
    
    //converting character octal table into long octal table
    for(int i=0; i<strlen(octal_char); i++){
        octal_long[i] = char_to_long(octal_char[i]);
    }

    //converting octal long table into single decimal long
    long odecimal_long = nsys_to_decimal(octal_long, strlen(octal_char), 8);


    //decimal char to long conversion
    //Max decimal lenght: 10
    long decimal_long[11];
    strcpy(decimal_char,argv[3]);
    
    //converting character decimal table into long decimal table
    for(int i=0; i<strlen(decimal_char); i++){
        decimal_long[i] = char_to_long(decimal_char[i]);
    }

    //converting decimal long table into single decimal long
    long ddecimal_long=0;
    for(int i=0; i<strlen(decimal_char); i++){
        ddecimal_long = ddecimal_long*10 + decimal_long[i];
    }


    //Hexadecimal tp decimal conversion
    //Max Hex lenght: 8
    long hexadecimal_long[9];
    strcpy(hexadecimal_char,argv[4]);
    
    //converting character hexadecimal table into long hexadecimal table
    for(int i=0; i<strlen(hexadecimal_char); i++){
        hexadecimal_long[i] = char_to_long(hexadecimal_char[i]);
    }

    //converting hexadecimal long table into single decimal long
    long hdecimal_long = nsys_to_decimal(hexadecimal_long, strlen(hexadecimal_char), 16);





//returning resault to PHP trought printf
printf("%s ",binary_char);
printf("%i ",bdecimal_long);
decimal_to_nsys(bdecimal_long, binary_char, 33, 2, true);
printf("%s\n", binary_char);


printf("%s ",octal_char);
printf("%i ",odecimal_long);
decimal_to_nsys(odecimal_long, octal_char, 12, 8, true);
printf("%s\n",octal_char);


printf("%s ",decimal_char);
printf("%i ",ddecimal_long);
decimal_to_nsys(ddecimal_long, decimal_char, 11, 10, true);
printf("%s\n",decimal_char);

printf("%s ",hexadecimal_char);
printf("%i ",hdecimal_long);
decimal_to_nsys(hdecimal_long, hexadecimal_char, 9, 16, true);
printf("%s\n",hexadecimal_char);

return(0);
}


//todo
//optimize code
//add signed binary option
//make GUI look good