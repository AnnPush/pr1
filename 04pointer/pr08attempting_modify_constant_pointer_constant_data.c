#include <stdio.h>

int main(void)
{
	int x = 5;
	int y;
	
	const int *const ptr = &x;
	printf("%d\n", *ptr);
	
	*ptr = 7;
	ptr = &y;
}
