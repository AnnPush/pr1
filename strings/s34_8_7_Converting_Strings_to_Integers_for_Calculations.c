#include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #define SIZE 4
 
 int main(void)
 {
	 char s[20];
	  long x = 0;
	
	puts("Enter four strings that represent integers:");
	for (int i = 0; i < SIZE; i++)
	{
		 scanf("%s\n", &s[i]);
		 x = x + strtol(&s[i], 0, 0);
		 printf("\n%ld\n", x);
	}
	
	
		 printf("\n%ld", x);
	
 

}
