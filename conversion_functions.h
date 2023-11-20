#ifndef CONVERSION_FUNCTIONS_H
#define CONVERSION_FUNCTIONS_H

long char_to_long(char character);
long nsys_to_decimal(long numbers[], int lenght, int n);
void decimal_to_nsys(long decimal, char* number, int x ,int n , bool first_run);
#endif