/*Write a function integerPower(base, exponent) that returns the value of
base^exponent
For example, integerPower(3, 4) = 3 * 3 * 3 * 3. Assume that exponent is a positive, nonzero integer,
and base is an integer. Function integerPower should use for to control the calculation. Do
not use any math library functions.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int integerPower(int, int);

int main()
{
    int base, exponent;
    
    puts("Enter base:");
    scanf("%d", &base);
    
    puts("Enter exponent:");
    scanf("%d", &exponent);
    
    if(exponent <= 0)
    {
        puts("Error");
    }
    else
    {
        printf("Result: %d\n", integerPower(base, exponent));
    }
}  

int integerPower(int b, int e)
{
    int p = 1;
        
    for(int i = 1; i <= e; i++)
    {
        p = p * b;
    }
     return p;
}
