/*Использование сканирующего набора*/

#include <stdio.h>

int main(void)
{
	char z[9];
	
	printf("%s", "Enter string: ");
	scanf("%8[aeiou]", z);
	
	printf("The input was \"%s\"\n", z);
}
