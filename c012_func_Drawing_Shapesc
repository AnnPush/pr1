#include <stdio.h>

void isSquare( char*);
void isRectangle( char*);
void isTriangle( char*);

int main()
{
    int var;
	char* fillCharacter;

    printf("%s", "Enter fillCharacter:\n");
    scanf("%s", &fillCharacter);
    
	printf("%s", "Enter Square - 1:\nEnter Rectangle - 2:\nEnter Triangle - 3:\n");
	scanf("%d", &var);

    switch(var)
	{
		case 1:
			isSquare(fillCharacter);
		    break;
		case 2:
			isRectangle(fillCharacter);
			break;
		case 3:
			isTriangle(fillCharacter);
			break;
		case '\n':
		case ' ':
		case '\t':
		    break;
		default:
		    printf("%s", "Incorrect letter entered./\nEnter a new integer.\n");
		    break;
		
	}
}

void isSquare( char* fillChar)
{
	int side;
	
	printf("%s","Enter side:");
	scanf("%d", &side);

    for(int i = 1; i <= side; i ++)
    {
        for(int j = 1; j <= side; j ++)
        {
            if(j == side)
            printf("%c\n", fillChar);
            else
            printf("%c", fillChar);
        }
    }    
        
}

void isRectangle( char* fillChar)
{
    int side1;
    int side2;
    
	printf("%s","Enter side1:");
	scanf("%d", &side1);

	printf("%s","Enter side2:");
	scanf("%d", &side2);

    for(int i = 1; i <= side1; i ++)
    {
        for(int j = 1; j <= side2; j ++)
        {
            if(j == side2)
            printf("%c\n", fillChar);
            else
            printf("%c", fillChar);
        }
    }  
}

void isTriangle( char* fillChar)
{
	int height;
	
	printf("%s","Enter height:");
	scanf("%d", &height);

    for(int i = 1; i <= height; i ++)
    {
        for(int j = 1; j <= height - i; j ++)
        {
            printf("%s", " ");
        }
        
        for(int j = 1; j <= i*2 - 1; j ++)
        {
            printf("%c", fillChar);
        }
        printf("%s", "\n");
    }    
        
}
