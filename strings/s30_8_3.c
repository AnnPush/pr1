/*Что выводится(если вообще выводится) при выполнении каждого из следующих операторов С?
Если оператор содержит ошибку, охарактеризуйте ее и укажите, как ее исправить.
Предположим, что объявлены следующие переменные:*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
	char s1[50] = "jack";
	char s2[50] = "jill";
	char s3[50];
	
	//a)
	printf("%c%s", toupper(s1[0]), &s1[1]);
    
    //Jack

    //b)
    printf("\n%s", strcpy(s3, s2));
    
    //jill
    
    //c
    printf("\n%s", strcat(strcat(strcpy(s3,s1), " and "), s2));
    
    //jack and jill
    
    //d
    printf("\n%u", strlen(s1) + strlen(s2));
    
    //8
    
    //e
    printf("\n%u", strlen(s3));
    
    //13
}
