#ifndef FUNCTIONS_H
#define FUNCTIONS_H

long char_to_long(char character);
long nsys_to_decimal(long numbers[], int lenght, int n);
void decimal_to_nsys(long decimal, char* number, int x ,int n , bool first_run);
long conversion(char nsys_char[], long nsys_long[], int n, int sgnd);
void log_print(char* binary_char, int sign, char* octal_char, char* decimal_char, char* hexadecimal_char, char minus, int input_type);
#endif