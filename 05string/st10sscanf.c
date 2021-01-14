#include <stdio.h>

int main(void)
{
	char s[] ="3124 76.678";
	int x;
	double y;
	
	sscanf(s, "%d%lf", &x, &y);
	printf("%s\n%s%6d\n%s%8.3f\n",
	"The values stored in character array s are:",
	"integer:", x, "double:", y);
}
