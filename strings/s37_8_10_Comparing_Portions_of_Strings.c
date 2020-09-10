/*Напишите программу, которая использует функцию strcnmp для сравнения двух строк, введенных пользователем. 
Программа должна вводить число сравниваемых символов. Программа должна определить, является ли первая 
строка меньшей, равной или большей второй строки.*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[20];
	char s2[20];
	int m;
	int n1, n2, n;
	
	puts("Enter two string:");
	scanf("%s%s", s1, s2);
	n1 = strlen(s1);
	n2 = strlen(s2);
	if(n1<n2)
	{
		n = n1;
	}
	else 
	{
		n = n2;
	}
	printf("Kol. srav. simv.: %d\n", n);
	m = strncmp(s1, s2, n);
	
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

