#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctyps.h>

int main(int argc, string argv[])
{
// checks if there is only one command line arg 
    if (argc !=2)
    {
        printf ("Please enter only one positive numeric amount in the command line.\n");
        return 1;
    }
// checks if command line arg is an int
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf ("please enter a postive int.\n");
            return 1;
        }
    }
 // converts string to int 
    int key = atoi(argv[1]);
 // check if key is negative
    if (key<0)
    {
        printf("Enter a non negative integer.\n");
        return 1;
    }
    
// get string from user to encrypt
    string phrase = GetString();
    
// lay out the string for encryption
    for (int i = 0, n = strlen(phrase); i < n; i++)
    {
//check upper
        if (isupper(phrase [i]))
        {
            //convert, first drop down to alphabetical index
            phrase[i] = phrase[i] - 'A';
            //use function given
            phrase[i] = (phrase[i] + key) % 26;
            //convert back to ASCII values and print back
            phrase[i] = phrase[i] + 'A';
            printf ("%c", phrase[i]);
        }
//check lower           
        if (islower(phrase[i]))
        {
            //convert to numeric index
            phrase[i] = phrase[i] - 'a';
            //use the convert function 
            phrase[i] = (phrase[i] + key) % 26;
            //convert to ASCII
            phrase[i] = phrase[i] + 'a';
            printf ("%c", phrase[i]);
        }
//non numeric spaces and punctuation
        else if (isalpha(phrase[i]) == 0)
        {
            printf ("%c", phrase[i]);
        }
    }
// new line
printf("\n");
// sucessful operation
return 0;
}
