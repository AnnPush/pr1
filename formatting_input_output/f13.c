/*Чтение чисел с плавающей точкой*/

#include <stdio.h>

int main(void)
{
	double a, b, c;
	
	puts("Enter three floating-point numbers: ");
	scanf("%le%lf%lg", &a, &b, &c);
	
	printf("\nHere are the numbers entered in plain: ");
	puts("floating-point notation:\n");
	printf("%f\n%f\n%f\n", a, b, c);
}
