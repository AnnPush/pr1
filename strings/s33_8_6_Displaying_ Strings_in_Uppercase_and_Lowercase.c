/*Напишите программу, которая вводит строки текста в массив символов
s[100]. Выведите строки в верхнем и нижнем регистрах.*/

#include <stdio.h>
#include <ctype.h>
#define SIZE 100

int main(void)
{
	char s[SIZE];
	puts("Enter a line of text:\n");
	
	fgets(s, SIZE, stdin);
	
	for(int i =0; s[i]; i++)
	{   	
	    printf("%c", tolower(s[i]));
	}
	
	for(int i =0; s[i]; i++)
	{  	
		printf("%c", toupper(s[i]));    
	}
}
