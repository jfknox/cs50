#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER 5 

int main (void)
{
    string students [NUMBER];
    for  (int i = 0; i < NUMBER; i++)
    {
        printf ("Enter student name.%d\n", i + 1);
        students [i] = GetString();
    }
    srand(time(NULL));
    int name= rand() % NUMBER;
    printf ("%s\n", students[name]);
    
    
    
    


}
