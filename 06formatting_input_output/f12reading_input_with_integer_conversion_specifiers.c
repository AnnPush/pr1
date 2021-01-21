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

/*
Enter seven integers:                                                                                                                                                              
-70 -70 070 0x70 70 70 70                                                                                                                                                          
                                                                                                                                                                                   
The input displayed as decimal integers is:                                                                                                                                        
-70 -70 56 112 56 70 112    
*/
