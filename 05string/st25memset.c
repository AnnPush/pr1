#include <stdio.h>
#include <string.h>

int main(void)
{
	char string1[15] = "BBBBBBBBBBBBBB";
	
	printf("string1 = %s\n", string1);
	printf("string1 after memset = %s\n",
	     (char *)memset(string1, 'b', 8));
}
