#include <stdio.h>
#include <math.h>

double hypotenuse(double a, double b);

int main(void)
{
    printf("1. %.2f\n", hypotenuse(3.0, 4.0));
    printf("2. %.2f\n", hypotenuse(5.0, 12.0));
    printf("3. %.2f\n", hypotenuse(8.0, 15.0));
}

double hypotenuse(double a, double b)
{
    return sqrt(a * a + b * b);
}

