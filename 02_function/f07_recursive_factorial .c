// Recursive factorial function/
#include <stdio.h>

unsigned long long int factorial(unsigned int number);

int main(void)
{
	unsigned int i;

	// during each iteration, calculate
	// factorial(i) and display result
	for (i = 0; i <= 10; ++i)
	{
		printf("%u! = %LLu\n", i, factorial(i));
	}
}

// recursive definition of function fsctorial
unsigned long long int factorial(unsigned int number)
{
	// base case
	if (number <= 1)
	{
		return 1;
	}
	else // recursive step
	{
		return (number * factorial(number - 1));
	}
}
