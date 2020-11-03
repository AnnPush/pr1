//Static array are initialized to zero if not explicitly initialized
#include <stdio.h>

void staticArrayInit(void);
void automaticArrayInit(void);

int main(void)
{
	puts("First call to each function:");

	staticArrayInit();
	automaticArrayInit();

	puts("\n\nSecond call to each function:");

	staticArrayInit();
	automaticArrayInit();
}

void staticArrayInit(void)
{
	static int array1[3];

	puts("\nValues on entering staticArrayInit:");

	for(size_t i = 0; i <= 2; ++i)
	{
		printf("array1[%u] = %d ", i, array1[i]);
	}

	puts("\nValues on exiting staticArrayInit:");

	for(size_t i = 0; i <= 2; ++i)
	{
		printf("array1[%u] = %d ", i, array1[i] += 5);
	}

}

void automaticArrayInit(void)
{
	int array2[3] = {1, 2, 3};

	puts("\nValues on entering automaticArrayInit:");

	for(size_t i = 0; i <= 2; ++i)
	{
		printf("array2[%u] = %d ", i, array2[i]);
	}

	puts("\nValues on exiting automaticArrayInit:");

	for(size_t i = 0; i <= 2; ++i)
	{
		printf("array2[%u] = %d ", i, array2[i] += 5);
	}

}
