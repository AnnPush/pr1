#include <stdio.h>

int isReversingDigits(int);

int main()
{
	int digit;

	printf("%s\n", "Enter digit:");
	scanf("%d", &digit);

	printf("New digit: %d\n", isReversingDigits(digit));
}

int isReversingDigits(int d)
{
	int newDigit =0;

	while( d!= 0)
	{
		newDigit = (newDigit * 10) + (d % 10);
		d = (d - (d % 10)) / 10;
	}
    return newDigit;
}
