#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[] = "ABCDEFG";
	char s2[] = "ABCDXYZ";
	
	printf("%s%s\n%s%s\n\n%s%2d\n%s%2d\n%s%2d\n",
	"s1 = ", s1, "s2 = ", s2,
	"memcmp(s1, s2, 4) = ", memcmp(s1, s2, 4),
	"memcmp(s1, s2, 7) = ", memcmp(s1, s2, 7),
	"memcmp(s2, s1, 7) = ", memcmp(s2, s1, 7));
}
