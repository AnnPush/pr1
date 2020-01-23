//Будет выполняться пока не заполнит стек

#include <stdio.h>

int main()
{
	static int count = 1;
	++count;

	printf("%d", count);

	main();

	return 0;
}
