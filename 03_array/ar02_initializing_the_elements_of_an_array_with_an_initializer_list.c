//Initializing the elements of an array with an initializer list

#include <stdio.h>

int main(void)
{
	int n[5] = {32, 27, 64, 18, 95};

	printf("%s%13s\n", "Element", "Value");

	for(size_t i = 0; i < 5; ++i)
	{
		printf("%7u%13d\n", i, n[i]);
	}
}
