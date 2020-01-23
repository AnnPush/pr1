#include <stdio.h>

int gcd(int, int);

int main()
{
    int a, b;
    
    printf("%s", "Enter a and b:\n");
    scanf("%d %d", &a, &b);
    
	printf("gcd(%d,%d) = %d\n", a, b, gcd(a,b));
}

int gcd( int x, int y )
{
	if( y == 0)
	{
		return x;
	}
	return gcd(y, x % y);
}
