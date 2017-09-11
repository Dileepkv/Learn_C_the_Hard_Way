//
//  main.c
//  qsort_srand
//
//  Created by Anoja Rajalakshmi on 9/10/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int compare(const void *a, const void *b);

int main()
{
    int numbers[SIZE], x;
    
    srand((unsigned)time(NULL)); // Use current time as seed for random generator
    for(x=0;x<SIZE;x++)
        numbers[x] = rand() % 100 + 1;
    
    /* Display the unsorted array */
    puts("Unsorted array:");
    for(x=0;x<SIZE;x++)
        printf(" %3d",numbers[x]);
    putchar('\n');
    
    /* Sort the array */
    qsort(numbers,SIZE,sizeof(int),compare);
    
    /* Display the sorted array */
    puts("Sorted array:");
    for(x=0;x<SIZE;x++)
        printf(" %3d",numbers[x]);
    putchar('\n');
    
    return(0);
}

int compare(const void *a, const void *b)
{
    return( *(int *)a - *(int *)b ); //ascending order
    //return(*(int *)b - *(int *)a );// descending order
}

