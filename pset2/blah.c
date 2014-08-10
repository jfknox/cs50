#include <stdio.h>
#include <cs50.h>
#include <string.h>

int atoi_50(char* s);

int main(void)
{
    char* x = GetString();
    printf ("your string is %d chars long!\n", atoi_50(x));
    
    printf ("%i\n" , atoi_50(x));
    
}

int atoi_50(char* s)
{
    //new integer variable
    
    //loop through every char in s
    
    // subtract 0
    
    //multiply by power of 10
    
    // add into new int variable
    
    int sum = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
        {
        sum = 10 * sum + s[i] - '0';
        } 
        return sum;  
}

