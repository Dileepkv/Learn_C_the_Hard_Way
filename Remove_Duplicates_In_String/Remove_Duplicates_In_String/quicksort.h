//
//  quicksort.h
//  Quick sort is based on the divide-and-conquer approach based on the idea of choosing one element as a pivot element and partitioning the array around it such that:
//  Left side of pivot contains all the elements that are less than the pivot element Right side contains all elements greater than the pivot

//  It reduces the space complexity and removes the use of the auxiliary array
//
//  Created by Anoja Rajalakshmi on 9/6/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#ifndef quicksort_h
#define quicksort_h

/* Utitlity function to sort array A[] */
void quickSort(char *, int, int);
int partition(char *, int, int);
void swap(char *, char *);

#endif /* quicksort_h */
