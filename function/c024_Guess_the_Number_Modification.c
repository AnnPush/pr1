#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n = 1;
	int x;
	int a;
	int counter = 0;

	srand(time(NULL));

	while(n == 1)
	{
		x = 1 + rand() % 1000;

		printf("%s\n", "I have a number between 1 and 1000. Can you guess my number? Please type your first guess.");
		scanf("%d", &a);

		for(;;)
		{
			counter++;
			if(a < x)
			{
				printf("%s\n", "Too low.");
			}
			if(a > x)
			{
				printf("%s\n", "Too high.");
			}
			if(a == x)
			{
				if(counter <= 10)
				{
					printf("%s\n", "Either you know the secret or you got lucky!");
				
				    if(counter == 10)
				    {
					    printf("%s\n", "Ahah! You know the secret!");
				    }
				}
				else
				{
					printf("%s\n", "You should be able to do better!");
				}
				printf("%s\n", "Very good! Continue: 1, Exit: 0");
				scanf("%d", &n);
				if(n == 1)
				{
				    counter = 0;
				}
				break;
			}
			else
			{
				printf("%s\n", "Please try again.");
				scanf("%d", &a);
			}
		}

	}
}
