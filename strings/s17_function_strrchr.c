#include <stdio.h>
#include <string.h>

int main(void)
{
	const char *string1 = "A zoo has many animals including zebras";
	
	int c = 'z';
	
	printf("%s\n%s'%c'%s\"%s\"\n",
	"The remainder of string1 beginning with the",
	"last occurrence of character ", c,
	" is: ", strrchr(string1, c));
}
