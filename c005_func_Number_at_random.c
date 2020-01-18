/*For each of the following sets of integers, write a single 
statement that will print a number at random from the set.
1) 2, 4, 6, 8, 10.
2) 3, 5, 7, 9, 11.
3) 6, 10, 14, 18, 22.*/

#include <time.h>

int main(void)
{
	int number1;
	int number2;
	int number3;
	
	srand(time(NULL));
	number1 = 2 * (1 + rand()%5);
	number2 = 2 * (1 + rand()%5) + 1;
	number3 = 4 * (1 + rand()%5) + 2;
	
	printf("Number1 = %d\n", number1);
	printf("Number2 = %d\n", number2);
	printf("Number3 = %d\n", number3);
}
