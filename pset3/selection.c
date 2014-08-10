#include <stdio.h>
#include <cs50.h>

void selection_sort(int values[], int n);
{
    //while list is out of order
    for (int i = 0; i < n; i++)
    {
        int smallest = values[i];
        int smallest_location = i;
        //go through the entire list
        for (int j = i + 1; j < n; j++)
        { 
            // go through list and find smallest int
            if (smallest > values [j])
            {
                smallest = smallest[j]
                smallest_location = j;
            }
        }
        // move the beginning of the list to the smallest number
        values[smallest_location] = values [i];
        
        // move int into the first space after the organized list
        values [i] = smallest;    
        
    
    }
}
