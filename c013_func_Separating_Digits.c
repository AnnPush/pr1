#include <stdio.h>

void isPrintDigit(int);

int main()
{
	int digit;

	printf("%s", "Enter integer (1 - 32767):");
	scanf("%d", &digit);

	if(digit >= 1 && digit <= 32767)
	{
		isPrintDigit(digit);
	}
	else
	{
		printf("%s", "Error!");
	}
}

void isPrintDigit(int dig)
{
	for(int i = 10000; i > 0; i /= 10)
	{
		if(dig / i != 0)
		{
			printf("%d", dig / i);
			printf("%s", " ");
		}
		dig %= i;
	}
}
