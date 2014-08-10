#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
// checks if there is only one command line arg 
    if (argc !=2)
    {
        printf ("Please enter only one string in the command line.\n");
        return 1;
    }
// checks if command line arg is an string
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isdigit(argv[1][i]) || ispunct(argv[1][i]))
        {
            printf ("please enter a string.\n");
            return 1;
        }
    }
//convert command line arg (key) to string and create length variable
    string key = argv [1];
     
// get string from user to encrypt
    string phrase = GetString();

// lay out the string for encryption, k is the key index location
    for (int i = 0, k = 0, n = strlen(phrase); i < n; i++)
    {
        // create variable shift that takes a letter in key and puts it on a numeric scale the ? is used as a conditional operator 
        // the syntax for ? is (conditon ? if true : if false) also % allows wrap around. 
        int shift = (key[k % strlen(key)] >= 'a' && key[k % strlen(key)] <= 'z') ? (key[k % strlen(key)] - 'a') : (key[k % strlen(key)] - 'A');  
//check upper
        if (isupper(phrase [i]))
        {
            //convert, first drop down to alphabetical index
            phrase[i] = phrase[i] - 'A';
            //use function given
            phrase[i] = (phrase[i] + shift) % 26;
            //convert back to ASCII values and print back
            phrase[i] = phrase[i] + 'A';
            printf ("%c", phrase[i]);
            //add one to k
            k++;
        }
//check lower           
        if (islower(phrase[i]))
        {
            //convert to numeric index
            phrase[i] = phrase[i] - 'a';
            //use the convert function 
            phrase[i] = (phrase[i] + shift) % 26;
            //convert to ASCII
            phrase[i] = phrase[i] + 'a';
            printf ("%c", phrase[i]);
            k++;
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
