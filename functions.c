#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "functions.h"


long char_to_int(char character){
    
        //converts character into long value
        switch (character)
        {
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            return(character - '0');
            break;
        case 'A':
            return(10);
            break;
        case 'B':
            return(11);
            break;
        case 'C':
            return(12);
            break;
        case 'D':
            return(13);
            break;
        case 'E':
            return(14);
            break;
        case 'F':
            return(15);
            break;
        
        default:
            return(0);
            break;
        }
}


//converts number in any given n-based system into single decimal long
//arguments: list of longs, list lenght ,source numeral system 
long nsys_to_decimal(long numbers[], int lenght, int n){
    long resault=0;
    for(int i=0; i<lenght; i++){
        resault += numbers[i]*pow(n,lenght-1-i);
    }

return(resault);
}


char mod; 
//converts decimal number into number in given n-based system
//arguments(long in decimal system, pointer to destination string, max lenght of pointed string, n, firt run bool)
void decimal_to_nsys(long decimal, char* number, int x ,int n , bool first_run){
    

    
    if(x>=0){

        if(first_run){
        //marking end of the string
        x = x-1;
        number[x] = '\0';
        x -= 1;
        }

        if (decimal>0){

            switch (decimal%n)
            {
            case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
                mod = decimal%n + '0';
                break;
            case 10:
                memcpy(&mod,"A",1);
                break;
            case 11:
                memcpy(&mod,"B",1);
                break;
            case 12:
                memcpy(&mod,"C",1);
                break;
            case 13:
                memcpy(&mod,"D",1);          
                break;
            case 14:
                memcpy(&mod,"E",1);
                break;
            case 15:
                memcpy(&mod,"F",1);
                break;
            default:
                break;
        }



        //copying resaulting character into next memory byte of "list" table, cell adress increments by 1 with each loop execution
        memcpy(number+x,&mod,1);
        decimal = decimal/n;

        decimal_to_nsys(decimal, number, x-1, n, false);
        }
        else{
        memcpy(number+x,"0",1);
        decimal_to_nsys(0, number, x-1, n, false);
        }

    }
}



long conversion(char nsys_char[], long nsys_long[], int n, int sgnd){

    if(sgnd == 1 && n == 2){
    //geting rid of stuff left in memory 
    nsys_long[0] = 0;

    }

    //converting character nsys table into long nsys table
        for(int i=sgnd; i<strlen(nsys_char); i++){
            nsys_long[i] = char_to_int(nsys_char[i]);
        }

        //converting nsys long table into single decimal long
        return(nsys_to_decimal(nsys_long, strlen(nsys_char), n));


}


void log_print(char* binary_char, int sign, char* octal_char, char* decimal_char, char* hexadecimal_char, char minus, int input_type){
    
FILE* file = fopen("log.txt", "a");

fprintf(file, "%s %i %c%s %c%s %c%s %i\n", binary_char, sign, minus, octal_char, minus, decimal_char, minus, hexadecimal_char, input_type);
printf("%s\n %c%s\n %c%s\n %c%s\n %i\n", binary_char, minus, octal_char, minus, decimal_char, minus, hexadecimal_char, input_type);

fclose(file);
}