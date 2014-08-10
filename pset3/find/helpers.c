/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
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

/**
 * Sorts array of n values.
 */
// create a swap function to swap numbers
void swap(int* i, int* j)
{
    int tmp = *i;
    *i = *j;
    *j = tmp;
}
 
 
void sort(int values[], int n)
{   
    //declare variable k to keep track of whether or not there has been a swap. 
    int k = 1;
    do
       {
       //make swap equal to zero 
        k = 0;
        // go through list
        for (int i = 0; i < n; i++)
            {
            //compare adjacent elements and swap larger element to right if necessary
            if ( values[i] >  values[i + 1])
                {
                swap (&values[i], &values[i + 1]);
                // add to k count
                k++;
                }
            
            }
        //if k count != 0 then complete loop again
        }
        while (k != 0);
}


