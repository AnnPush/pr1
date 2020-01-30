#include <stdio.h>
#define n 1000

int main()
{
	int a[n]= {0} ;

	for(int i = 2; i < n; ++i)
    {
	    a[i] = 1;
	}

	for(int i = 2; i * i <= n; ++i)
	{
		if (a[i] == 1)
		{
		   for(int k = i * i; k < n; k += i)
		   {
			   a[k] = 0;
		   }
		}
	}
	printf("%s", "\Prime numbers:\n");

	for (int i = 2; i < n; ++i)
	{
		if (a[i] == 1)
		{
		    printf("%5d", i);
		}
	}
	printf("%s", "\n");
}
