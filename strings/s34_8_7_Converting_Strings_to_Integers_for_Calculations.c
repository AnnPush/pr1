/*Напишите программу, которая вводит 4 строки, представляющие целые значения,
 преобразует строки в целые числа, суммирует и выводит сумму 4 значений.*/
 
 #include <stdio.h>
 #include <stdlib.h>
 #define SIZE 4
 
 int main(void)
 {
	char s[20];
	long x = 0;
	
	puts("Enter four strings that represent integers:");
	for(int i = 0; i < SIZE; ++i)
	{
		 scanf("%s", &s[i]);
		 x = x + strtol(&s[i], 0, 0);
	}
	
	printf("\n%ld", x);
}
