#include <stdio.h>

int isEven(int);

int main()
{
	int number;

	puts("Enter number:(Exit: 0)");
	scanf("%d", &number);

	while (number != 0)
	{
		if(isEven(number) == 1)
		{
			puts("Even");
		}
		else
		{
                        puts("Odd");
		}
		puts("Enter number:(Exit: 0)");
	        scanf("%d", &number);
	}
}

int isEven(int n)
{
	int t;
	float z;
	z = n % 2;

	if(z == 0)
	{
		t = 1;
	}
	else
	{
		t = 0;
	}
	return t;
}
