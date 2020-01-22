#include <stdio.h>

void isSquare(int, char*);

int main()
{
    int number;
	char* fillCharacter;

    printf("%s","Enter number:\n");
    scanf("%d", &number);

    printf("%s", "Enter fillCharacter:\n");
    scanf("%s", &fillCharacter);
    
    isSquare(number, fillCharacter);
}

void isSquare(int n, char* fillChar)
{
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            if(j == n)
            printf("%c\n", fillChar);
            else
            printf("%c", fillChar);
        }
    }    
        
}
