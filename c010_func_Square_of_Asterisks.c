/*(Square of Asterisks) Write a function that displays a solid square of asterisks whose side is
specified in integer parameter side. For example, if side is 4, the function displays.*/

#include <stdio.h>

void isSquare(int);

int main()
{
    int asterisks;

    puts("Enter asterisks:");
    scanf("%d", &asterisks);
    
    isSquare(asterisks);
}

void isSquare(int ast)
{
    for(int i = 1; i <= ast; i ++)
    {
        for(int j = 1; j <= ast; j ++)
        {
            if (j == ast)
            printf("*\n");
            else
            printf("*");
        }
    }    
        
}
