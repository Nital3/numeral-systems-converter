// calculator function to converting

#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdbool.h>

//global variables to pass data between functions   
char binary_char[33];
char octal_char[12];
char decimal_char[11];
char hexadecimal_char[9];



//note: all functions work on tables

long char_to_long(char character){
    
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






// main function recives starting arguments 
//argc - number of arguments passed
//argv - table of arguments, each cell contains string pointer, argv[0] == name of program
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