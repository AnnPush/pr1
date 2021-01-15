#include <stdio.h>
#include <string.h>

int main(void)
{
	char string[] = "This is a sentence with 7 tokens";
	
	printf("%s\n%s\n\n%s\n",
	"The string to be tokenized is:", string,
	"The tokens are:");
	
	char *tokenPtr = strtok(string, " ");
	
	while(tokenPtr != NULL)
	{
		printf("%s\n", tokenPtr);
		tokenPtr = strtok(NULL, " ");
	}
}
