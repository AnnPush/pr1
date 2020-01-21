#include <stdio.h>
int isPerfect(int);

int main()
{
	for(int i = 1; i <= 10000; i++)
	{
		if(isPerfect(i) == 1)
		{
			printf("%d factors: ", i);
			for(int j = 1; j <= i; j++)
			{
				if(i%j == 0 && i != j)
					printf("%d ", j);
			}
			printf("%s", "\n");
		}
	}
}

int isPerfect(int a)
{
    	int sum = 0;
		for( int j = 1; j < a; j++)
		{
			if(a%j == 0)
			sum += j;
		}
		if( sum == a)
			return 1;
		else
			return 0;
}
