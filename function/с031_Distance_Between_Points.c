#include <stdio.h>
#include <math.h>

float fun(float, float, float, float);

int main()
{
	float x1, x2, y1, y2;
	printf("%s\n", "Enter x1, y1, x2, y2:");
	scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
	
    printf("%f", fun(x1, y1, x2, y2));
}

float fun(float a, float b, float c, float d)
{ 
	return sqrt((c - a) * (c - a) + (d - b) * (d - b));
}
