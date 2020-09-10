/*Напишите программу, которая использует функцию strcmp для сравнения двух строк,
введенных пользователем. Программа должна определять, является ли первая строка
меньшей, равной или большей второй строки.*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[20];
	char s2[20];
	int m;
	
	puts("Enter two string:");
	scanf("%s%s", s1, s2);
	
	m = strcmp(s1, s2);
	
	if( m == 0)
	{
		puts("s1 = s2");
	}
	else if(m <0)
	{
		puts("s1 < s2");
	}
	else
	{
		puts("s1 > s2");
	}
}
