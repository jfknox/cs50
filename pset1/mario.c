#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int height = 0;
    printf("Hello, Mushroom Kingdom\n");
    printf("Enter a number between 0 and 23, inclusive.\n");

    do
    {   
        printf("Height:");
        height = GetInt();
        
    if (height<0 || height>23 || height = NULL)
    {
       printf("Please Try Again.\n");
    if (height == 0)
    {//zero gets its own unique entry
        return 0;
    }
    }  
    }
    while (height<=-1 || height>23);
    
  //to create the number of rows neded
 for  (int row = 0; row < height; row++)
 {
 // to create the number of spaces for each row 
 for (int space = 0; space< height - row - 1; space++)
 {
    printf ("%s", " ");
 }
 // to create the number of hash's printed for each row
    for  (int hash = 0; hash< row + 2; hash++)
    {
        printf ("#");
    }
    //print new line is down here to create new line in the terminal at end of pyramid
 printf("\n");   
 }
 
  
  

}
    
