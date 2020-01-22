#include <stdio.h>

int power(int, int);

int main()
{
	int base, exponent;

	printf("%s", "Enter base:");
	scanf("%d", &base);

	printf("%s", "Enter exponent:");
	scanf("%d", &exponent);

	if(exponent <= 0)
	{
		printf("%s", "Error!");
	}
	else
	{
		printf("Result: %d\n", power(base, exponent));
	}
}

int power(int b, int e)
{
	int n = 1;

	for(int i = 1; i <= e; i++)
	{
		n = n * b;
	}
	return n;
}
