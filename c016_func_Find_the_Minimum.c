# include <stdio.h>

float isMinimum(float, float, float);

int main()
{
	float i1, i2, i3;
	printf("%s", "Enter three floating-point numbers:");
	scanf("%f%f%f", &i1, &i2, &i3);

	printf("Minimum: %.2f\n", isMinimum(i1, i2, i3));
}

float isMinimum( float a, float b, float c)
{
	float min;

	if(a < b)
		min = a;
	else
		min = b;
	
	if(c < min)
		min = c;
	return min;
}
