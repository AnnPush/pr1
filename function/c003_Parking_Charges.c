// c003_func_Parking_Charges.c
#include <stdio.h>

float calculateCharges(float hours);

int main(void)
{
    float t1;
	float t2;
	float t3;
	float ch;
	float t;
	
   
     printf("How many hours did each car stay?\n Enter time1, time2, time3:\n");
     scanf("%f%f%f", &t1, &t2, &t3);

	 printf("%s%13s%13s\n", "Car", "Hours", "Charge");
	 printf("1.%13.1f%13.2f\n", t1, calculateCharges(t1));
	 printf("2.%13.1f%13.2f\n", t2, calculateCharges(t2));
	 printf("3.%13.1f%13.2f\n", t3, calculateCharges(t3));

	 t = t1 + t2 + t3;
	 ch = calculateCharges(t1) + calculateCharges(t2) + calculateCharges(t3);


     printf("TOTAL%10.1f%13.2f\n", t, ch);
}
float calculateCharges(float hours)
{
    
    
    float charge;
    
    if(hours >= 24)
    {
        charge = 10.0;
    }
    else if(hours <= 3)
    {
        charge = 2.0;
    }
    else
    {
        charge = 2.0 + 0.5 *(hours - 3);
    }
    return charge;
}

