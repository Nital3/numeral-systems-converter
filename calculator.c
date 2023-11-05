// calculator function to converting

#include<stdio.h>
#include<string.h>

// main function recives starting arguments 
//argc - number of arguments passed
//argv - table of arguments, each cell contains string pointer, argv[0] == name of program
int main(int argc, char* argv[]){

    for (int n=1; n<argc; n++){
        //prints nth arg + added control string
        printf("%s success!\n", argv[n]);

    }               


return(0);
}