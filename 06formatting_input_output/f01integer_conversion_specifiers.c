/*Использование спецификаторов преобразования целых чисел*/
#include <stdio.h>

int main(void)
{
	printf("%d\n", 455);
	printf("%i\n", 455);
	printf("%d\n", +455);
	printf("%d\n", -455);
	printf("%hd\n", 32000);
	printf("%ld\n", 2000000000);
	printf("%o\n", 455);
	printf("%u\n", 455);
	printf("%u\n", -455);
	printf("%x\n", 455);
	printf("%X\n", 455);	
}

/*455                                                                                                                                                                                  
455                                                                                                                                                                                  
455                                                                                                                                                                                  
-455                                                                                                                                                                                 
32000                                                                                                                                                                                
2000000000                                                                                                                                                                           
707                                                                                                                                                                                  
455                                                                                                                                                                                  
4294966841                                                                                                                                                                           
1c7                                                                                                                                                                                  
1C7 */
