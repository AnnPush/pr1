/*Ввод данных с шириной поля*/
#include <stdio.h>

int main(void)
{
	int x, y;
	
	printf("%s", "Enter a six digit integer: ");
	scanf("%2d%d", &x, &y);
	
	printf("The integers input were %d and %d\n", x, y);
}
