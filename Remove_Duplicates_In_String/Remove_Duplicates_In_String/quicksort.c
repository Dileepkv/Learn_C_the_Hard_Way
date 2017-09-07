//
//  quicksort.c
//
//  Created by Anoja Rajalakshmi on 9/6/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
#include "quicksort.h"


/* Implementation of Quick Sort
 A[] --> Array to be sorted
 p --> Starting index
 r --> Ending index
 */
void quickSort(char A[], int p, int r)
{
    int q; /* Partitioning index */
    if (p < r)
    {
        q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int partition(char A[], int p, int r)
{
    char x = A[r];
    int i = (p - 1);
    for (int j = p; j <= r - 1; j++){
        if (A[j] <= x){
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap (&A[i + 1], &A[r]);
    return (i + 1);
}


void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

