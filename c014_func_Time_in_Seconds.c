#include <stdio.h>

int isTime(int, int, int);

int main()
{
	int hours, minutes, seconds;

	printf("%s\n", "Enter three integer arguments (for hours, minutes, and seconds):");
	scanf("%d%d%d", &hours, &minutes, &seconds);

	printf("The number of seconds since the last time the clock struck 12:%d\n", isTime(hours, minutes, seconds));
}

int isTime(int h, int m, int s)
{
	h = h * 3600;
	m = m * 60;
	s = s + h + m;
	return s;
}
