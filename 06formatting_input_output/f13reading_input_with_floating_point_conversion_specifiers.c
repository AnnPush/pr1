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

/*
Enter three floating-point numbers:                                                                                                                                                
1.27987 1.27987e+03 3.38476e-06                                                                                                                                                    
                                                                                                                                                                                   
Here are the numbers entered in plain: floating-point notation:                                                                                                                    
                                                                                                                                                                                   
1.279870                                                                                                                                                                           
1279.870000                                                                                                                                                                        
0.000003  
*/
