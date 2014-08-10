#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
    printf ("Enter a string.\n");
    string word = GetString();
    
    for ( int i = 0, length = strlen(word); i < length; i++)
    {
        printf ("%c\n", word[i]);
    }
    
    
    


}
