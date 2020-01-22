#include <stdio.h>

int fibonacci(int);

int main()
{
	for(int i = 0; i < 20; i ++)
	{
		printf("Fibonacci: %d == %d\n", i, fibonacci(i));
	}
}

int fibonacci(int digit)
{
	if(0 == digit || 1 == digit)
		return digit;
	else
		return fibonacci(digit - 1) + fibonacci(digit - 2);
}
