/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm

    // specify rightbound and left bound position
    int rb = n-1;
    int lb = 0;

    // binary search
    while (rb >= lb)
    {
        int midpt = (rb+lb)/2;

        if (values[midpt] == value)
        return true;

        else if (values[midpt] > value)
        rb = midpt - 1;

        else
        lb = midpt + 1;
    }

    //only happens if true is not returned
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm

    // selection sort
    for (int i = 0, l = n - 1; i < l; i++)
    {
       int min = i;

       //check from next element onwards for min value. if cant find, min remains as i.
       for (int j = i + 1; j < n; j++)
       {
           if (values[j] < values[min])
           {
             min = j;
           }
       }

       //swap minth with ith position
       int firstp = values[i];
       values[i] = values[min];
       values[min] = firstp;
    }
}
