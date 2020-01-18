/*Write statements that assign random integers to the variable n in the following ranges:
1) 1 <= n <= 2
2) 1 <= n <= 100
3) 0 <= n <= 9
4) 1000 <= n <= 1112
5) –1 <= n <= 1
6) –3 <= n <= 11*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int number1;
	int number2;
	int number3;
	int number4;
	int number5;
	int number6;

	srand(time(NULL));
	number1 = 1 + rand() % 2;
	number2 = 1 + rand() % 100;
	number3 = rand() % 10;
	number4 = 1000 + rand() % 113;
	number5 =  rand() % 3 - 1;
	number6 =  rand() % 14 - 3;

	printf("Number1 = %d\n", number1);
	printf("Number2 = %d\n", number2);
	printf("Number3 = %d\n", number3);
	printf("Number4 = %d\n", number4);
	printf("Number5 = %d\n", number5);
	printf("Number6 = %d\n", number6);
}
