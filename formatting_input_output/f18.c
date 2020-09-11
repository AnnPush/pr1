/*Чтение и отбрасывание символов из входного потока*/

#include <stdio.h>

int main(void)
{
	int month = 0, day = 0, year = 0;
	
	printf("%s", "Enter a date in the form mm-dd-yyyy: ");
	scanf("%d%*c%d%*c%d", &month, &day, &year);
	printf("month = %d day = %d year = %d\n\n", month, day, year);
	
	printf("%s", "Enter a date in the form mm/dd/yyyy: ");
	scanf("%d%*c%d%*c%d", &month, &day, &year);
	printf("month = %d day = %d year = %d\n\n", month, day, year);
	
	
}
