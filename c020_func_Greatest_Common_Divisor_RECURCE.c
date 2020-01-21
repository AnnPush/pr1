#include <stdio.h>
#include <math.h>

int gcd(int, int);

int main()
{
	int digit1;
	int digit2;

	printf("%s", "Enter digits:");
	scanf("%d %d", &digit1, &digit2);

	printf("Greatest Common Divisor: %d\n", gcd(digit1, digit2));
}

int gcd(int d1, int d2)
{
	if(d2 == 0)
		return abs(d1);
	return gcd(d2, d1%d2);
}
