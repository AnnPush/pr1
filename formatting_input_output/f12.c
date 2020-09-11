/*Чтение целых*/
#include <stdio.h>

int main(void)
{
	int a, b, c, d, e, f, g;
	
	puts("Enter seven integers: ");
	scanf("%d%i%i%i%o%u%x", &a, &b, &c, &d, &e, &f, &g);
	
	puts("\nThe input displayed as decimal integers is: ");
	printf("%d %d %d %d %d %d %d\n", a, b, c, d, e, f, g);
}
