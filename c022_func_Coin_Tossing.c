#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip();

int main()
{
	int heads = 0;
	int tails = 0;
		
	srand(time(NULL));

	for(int i = 1; i <= 100; i++)
	{
	    
		if(flip() == 0)
		{
			printf("%s\n", "Heads");
			heads++;
		}
		else 
		{
			printf("%s\n", "Tails");
			tails++;
		}
	}
	printf("\nHeads: %d\nTails: %d\n ", heads, tails);
}

int flip()
{
	int number = rand();

	if(number % 2 == 0)
		return 0;
	else
		return 1;
}
