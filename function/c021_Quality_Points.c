#include <stdio.h>

int toQualityPoints(int);

int main()
{
	int average;

	printf("%s", "Enter average: ");
	scanf("%d", &average);

	if(average >= 0 && average <= 100)
	{
	    printf("Digit: %d\n", toQualityPoints(average));
	}
	else
	{
		printf("%s", "Error!");
	}
}

int toQualityPoints(int a)
{
	int point;

	if(a <= 100 && a >= 90)
		point = 4;
    if(a <= 89 && a >= 80)
		point = 3;
	if(a <= 79 && a >= 70)
		point = 2;
	if(a <= 69 && a >= 60)
		point = 1;
	if(a <= 59 )
		point = 0;

	return point;
}
