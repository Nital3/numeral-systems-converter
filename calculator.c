// calculator function to converting

#include<stdio.h>
#include<string.h>
#include<math.h>

//global variables to pass data between functions   
char binary_char[65];
char octal_char[23];
char decimal_char[21];
char hexadecimal_char[17];



//note: all functions work on tables

int char_to_int(char character){
    
        //converts character into int value
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


//converts number in any given n-based system into single decimal int
//arguments: list of ints, list lenght ,source numeral system 
int nsys_to_decimal(int numbers[], int lenght, int n){
    int resault=0;
    for(int i=0; i<lenght; i++){
        resault += numbers[i]*pow(n,lenght-1-i);
    }

return(resault);
}


//converts decimal number into number in given n-based system
//arguments(int in decimal system, pointer to destination string, lenght of pointed string, n)
void decimal_to_nsys(int decimal, char* number, int lenght ,int n){
    

    //Converting decimal numbers into numbers in n based system (Up to n=16)
    char mod;
    int x = lenght-1;

    //marking end of the string
    number[x] = '\0';


    while (decimal>0)
    {   
        x--;
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
    }

        while (x>=0)
        {
            x--;
            memcpy(number+x,"0",1);
        }
        


}




// main function recives starting arguments 
//argc - number of arguments passed
//argv - table of arguments, each cell contains string pointer, argv[0] == name of program
int main(int argc, char* argv[]){



    //Binary to decimal convertion
    //Max binary lenght: 64 digits
    int binary_int[65];
    strcpy(binary_char,argv[1]);
    
    //converting character binary table into int binary table
    for(int i=0; i<strlen(binary_char); i++){
        binary_int[i] = char_to_int(binary_char[i]);
    }

    //converting binary int table into single decimal int
    int bdecimal_int = nsys_to_decimal(binary_int, strlen(binary_char), 2);



    //Octal tp decimal conversion
    //Max Octal lenght: 22
    int octal_int[23];
    strcpy(octal_char,argv[2]);
    
    //converting character octal table into int octal table
    for(int i=0; i<strlen(octal_char); i++){
        octal_int[i] = char_to_int(octal_char[i]);
    }

    //converting octal int table into single decimal int
    int odecimal_int = nsys_to_decimal(octal_int, strlen(octal_char), 8);


    //decimal char to int conversion
    //Max decimal lenght: 20
    int decimal_int[21];
    strcpy(decimal_char,argv[3]);
    
    //converting character decimal table into int decimal table
    for(int i=0; i<strlen(decimal_char); i++){
        decimal_int[i] = char_to_int(decimal_char[i]);
    }

    //converting decimal int table into single decimal int
    int ddecimal_int=0;
    for(int i=0; i<strlen(decimal_char); i++){
        ddecimal_int = ddecimal_int*10 + decimal_int[i];
    }


    //Hexadecimal tp decimal conversion
    //Max Hex lenght: 16
    int hexadecimal_int[17];
    strcpy(hexadecimal_char,argv[4]);
    
    //converting character hexadecimal table into int hexadecimal table
    for(int i=0; i<strlen(hexadecimal_char); i++){
        hexadecimal_int[i] = char_to_int(hexadecimal_char[i]);
    }

    //converting hexadecimal int table into single decimal int
    int hdecimal_int = nsys_to_decimal(hexadecimal_int, strlen(hexadecimal_char), 16);





//returning resault to PHP trought printf
printf("%s ",binary_char);
printf("%i ",bdecimal_int);
decimal_to_nsys(bdecimal_int, binary_char, 65, 2);
printf("%s\n",binary_char);


printf("%s ",octal_char);
printf("%i ",odecimal_int);
decimal_to_nsys(odecimal_int, octal_char, 23, 8);
printf("%s\n",octal_char);


printf("%s ",decimal_char);
printf("%i ",ddecimal_int);
decimal_to_nsys(ddecimal_int, decimal_char, 21, 10);
printf("%s\n",decimal_char);

printf("%s ",hexadecimal_char);
printf("%i ",hdecimal_int);
decimal_to_nsys(hdecimal_int, hexadecimal_char, 17, 16);
printf("%s\n",hexadecimal_char);

//Variable size problem :(

return(0);
}