#include <stdio.h>
#include <string.h>

int main(void)
{
	const char *s = "This is a string";
	
	printf("%s\'%c\'%s\"%s\"\n",
	"The remainder of s after character ", 'r',
	" is found is ", (char *)memchr(s, 'r', 16));
}
