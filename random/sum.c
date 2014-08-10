#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
int sum(int n);

int main(int argc, string argv[])
{

int n = atoi (argv[1]);
printf ( "the sum of your number is %i \n", sum (n));

}


int sum(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return (n + sum(n - 1));
    
}
