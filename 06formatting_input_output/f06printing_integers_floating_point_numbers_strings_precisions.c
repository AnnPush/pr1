/*Использование точности при печати целых,
чисел с плавающей точкой и строк*/

#include <stdio.h>

int main(void)
{
	puts("Using precision for integers");
	int i = 873;
	printf("\t%.4d\n\n\t%.9d\n\n", i, i);
	
	puts("Using precision for floating-point numbers");
	double f = 123.94536;
	printf("\t%.3f\n\t%.3e\n\t%.3g\n\n", f, f, f);
	
	puts("Using precision for strings");
	char s[] = "Happy Birthday";
	printf("\t%.11s\n", s);
}

/*
Using precision for integers                                                                                                                                                         
        0873                                                                                                                                                                         
                                                                                                                                                                                     
        000000873                                                                                                                                                                    
                                                                                                                                                                                     
Using precision for floating-point numbers                                                                                                                                           
        123.945                                                                                                                                                                      
        1.239e+02                                                                                                                                                                    
        124                                                                                                                                                                          
                                                                                                                                                                                     
Using precision for strings                                                                                                                                                          
        Happy Birth   
*/
