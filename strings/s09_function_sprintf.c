#include <stdio.h>
#define SIZE 80

int main(void)
{
	int x;
	double y;
	
	puts("Enter an integer and a double:");
	scanf("%d%lf", &x, &y);
	
	char s[SIZE];
	sprintf(s, "integer:%6d\ndouble:%7.2f", x, y);
	
	printf("%s\n%s\n", "The formatted output stored in array s is:", s);
}
