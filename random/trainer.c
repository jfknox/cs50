#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int* getAge(void);

int main(int argc, string argv[])
{
    //make sure there is only one comand line argument to signifiy # of dolphins
    if (argc != 2)
    {
        return 1;
    }
    //string argv to int through atoi
    int dolphins = atoi(argv[1]);
    //check to be sure it is > 0
    if (dolphins <= 0)
    {
        printf ("enter a positive dolphin amount, bitch.\n");
        return 2;
    }
    //create array of size of the arg
    int* dolphin_ages [dolphins];
    
    //for each dolphin we call getAge
    for (int i = 0; i < dolphins; i++)
    {
        dolphin_ages[i] = getAge();
    }
    //create oldest variable
    int oldest = 0;    
    //search for oldest dolphin    
    for (int i = 0; i < dolphins; i++)
    {
        if (*dolphin_ages[i] > oldest)
        {
            oldest = *dolphin_ages[i];
        }
    }
    //print out the age of the oldest dolphin
    printf("the oldest dolphin is %i years old... whoop de shit.\n", oldest); 
}

int* getAge(void)
{
    //declare empty variable
    int* age =  malloc(sizeof(int));
    //ask user for an age
    do
    {
        printf("Age please... now dammit!\n");
        *age = GetInt();
            if (age < 0)
            {
                return 0;
            }
    }
    while (*age < 1);
    //return int*
    return age;    
}





