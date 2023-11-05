// calculator function to converting

#include<stdio.h>
#include<string.h>

// main function recives starting arguments 
//argc - number of arguments passed 
//argv - table of arguments, each cell contains string, argv[0] == name of program
int main(int argc, char* argv[]){

    //creates table of strings with lenght of 1
    char* success[1];               

    //creates string and ads it to 1st recived argument (outside program name)
    success[0] = " Success!";
    strcat(argv[1],success[0]);

    //prints 1st arg + added string
    printf("%s", argv[1]);


return(0);
}