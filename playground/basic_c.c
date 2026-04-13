/*
Practice Problem: 
Write a C program that takes a floating-point number (a decimal number, like 3.14159) 
from the user and prints it, formatted to display with only two decimal places.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>


int float_input_output() 
{
    
    char * input = "3.14";
    printf("Input string: %s\n", input);
    printf("String length: %lu\n", strlen(input));
    printf("Pointer size: %lu\n", sizeof(input));
    printf("Array size: %lu\n", strlen(input) + 1);
    printf("Element size: %lu\n", sizeof(input[0]));

    char * input = "3.14159";
    float num = atof(input);
    printf("Formatted number: %.2f\n", num);

    char * input2 = "75.35678";
    char num2[6];
    sprintf(num2, "%.2f", input2);
    printf("Formatted number: %f\n", atof(num2));

    char * input3 = "0.12345";
    
    char num3[strlen(input3)];
    int i = 0;
    while (input3[i] != '\0' && input3[i] != '.') {
        num3[i] = input3[i];
        i++;
    }
    num3[i] = input3[i++];  // Copy the decimal point
    num3[i++] = input3[i];  // Copy the first decimal digit
    num3[i] = '\0';  // Null-terminate the string

    char * input4 = "37.777779";
    float val = atof(input4);
    float rounded_down = floorf(val * 100) / 100;   /* Result: 37.77 */
    float nearest = roundf(val * 100) / 100;  /* Result: 37.78 */
    float rounded_up = ceilf(val * 100) / 100;      /* Result: 37.78 */

}

int main(int argc, char *argv[]) 
{
    return float_input_output(argc, argv);
}