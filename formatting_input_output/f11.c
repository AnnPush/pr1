/*Печать с флагом 0(нулем) заполняет поле ведущими нулями*/

#include <stdio.h>

int main(void)
{
	printf("%+09d\n", 452);
	printf("%09d\n", 452);
}