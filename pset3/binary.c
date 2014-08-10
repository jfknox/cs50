#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>

bool binary_search(int value, int values[], int n)
{
    int beginning = 0;
    int ending = n-1;
    
    // while length of list > 0 
    while (ending >= beginning)
    {
        //go to middle of list and check if our value is there. 
        int middle = (beginning + ending) / 2;
        if (values [middle] == value)
        {
            //if number found return true
            return true;
        }
        // if middle of list is greater then search left half
        else if (values[middle] > value)
        {
            ending = middle - 1;
        }
        // else if middle is less then search the right half 
        else
        {
            beginning = middle + 1;
        }
    }    
    return false;
}
