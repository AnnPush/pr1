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

/*
Enter a date in the form mm-dd-yyyy: 11-18-2000                                                                                                                                    
month = 11 day = 18 year = 2000                                                                                                                                                    
                                                                                                                                                                                   
Enter a date in the form mm/dd/yyyy: 11/18/2000                                                                                                                                    
month = 11 day = 18 year = 2000  
*/
