// calculator function to converting

#include<stdio.h>
#include<string.h>
#include<math.h>



//note: all functions work on tables

int char_to_int(char character){
    
        //converts character into int value
        switch (character)
        {
        case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0':
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






// main function recives starting arguments 
//argc - number of arguments passed
//argv - table of arguments, each cell contains string pointer, argv[0] == name of program
int main(int argc, char* argv[]){



    //Binary to decimal convertion
    //Max binary lenght: 64 digits
    char binary_char[64];
    int binary_int[64];
    strcpy(binary_char,argv[1]);
    
    //converting character binary table into int binary table
    for(int i=0; i<strlen(binary_char); i++){
        binary_int[i] = char_to_int(binary_char[i]);
    }

    //converting binary int table into single decimal int
    int bdecimal_int = nsys_to_decimal(binary_int, strlen(binary_char), 2);



    //Octal tp decimal conversion
    //Max Octal lenght: 22
    char octal_char[22];
    int octal_int[22];
    strcpy(octal_char,argv[2]);
    
    //converting character octal table into int octal table
    for(int i=0; i<strlen(octal_char); i++){
        octal_int[i] = char_to_int(octal_char[i]);
    }

    //converting octal int table into single decimal int
    int odecimal_int = nsys_to_decimal(octal_int, strlen(octal_char), 8);


    //decimal char to int conversion
    //Max decimal lenght: 20
    char decimal_char[20];
    int decimal_int[20];
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
    char hexadecimal_char[16];
    int hexadecimal_int[16];
    strcpy(hexadecimal_char,argv[4]);
    
    //converting character hexadecimal table into int hexadecimal table
    for(int i=0; i<strlen(hexadecimal_char); i++){
        hexadecimal_int[i] = char_to_int(hexadecimal_char[i]);
    }

    //converting hexadecimal int table into single decimal int
    int hdecimal_int = nsys_to_decimal(hexadecimal_int, strlen(hexadecimal_char), 16);



//returning resault to PHP trought printf
printf("%s ",binary_char);
printf("%i\n",bdecimal_int);
printf("%s ",octal_char);
printf("%i\n",odecimal_int);
printf("%s ",decimal_char);
printf("%i\n",ddecimal_int);
printf("%s ",hexadecimal_char);
printf("%i\n",hdecimal_int);






return(0);
}