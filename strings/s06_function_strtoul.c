#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	const char *string = "1234567abc";
	char *remainderPtr;
	
	unsigned long int x = strtoul(string, &remainderPtr, 0);
	
	printf("%s\"%s\"\n%s%lu\n%s\"%s\"\n%s%lu\n",
	"The original string is ", string,
	"The converted value is ", x,
	"The remainder of the original string is ",
	remainderPtr,
	"The converted value minus 567 is ", x - 567);
}
