/*Напишите программу, которая вводит 4 строки, представляющие значения с плавающей точкой, 
преобразует строки, удваивая значения, суммирует и выводит сумму 4 значений.*/

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #define SIZE 4
 
 int main(void)
 {
	char s[20];
	double sum = 0;
	double a = 0;
	
	puts("Enter four strings that represent integers:");
	for(int i = 0; i < SIZE; ++i)
	{
		 scanf("%s", &s[i]);
		 a = 2 * strtod(&s[i], 0);
		 sum += a;
		 a = 0;
	}
	
	printf("\n%.2f", sum);
}
