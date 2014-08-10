#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
  
    printf ("How much change is due?\n");
    float change = 0;
    
    if (change <= 0)
      {
         do
         {   
         printf ("Please enter a positive numeric amount.\n");
         change = GetFloat();
         }
         while (change<=0);
         }
     int cents = (int)round(change * 100); 
     
     int coins = 0;
     
        while (cents >= 25) 
     {
        cents= cents-25;
        coins++;
     }
     
       while (cents >= 10)
     {
        cents = cents-10;
         coins++;
     }
     
        while (cents >= 5)
     {
        cents = cents -5;
        coins ++;
     }
     
        while (cents >= 1)
     {
        cents = cents-1;
        coins++;
     }
         
    
 printf("%d\n", coins);
     
 }



