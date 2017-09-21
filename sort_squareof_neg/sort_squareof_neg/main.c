//
//  main.c
//  sort_squareof_neg
//  Given a sorted array that can have both negative and positive integers, write an algorithm to sort the array of the squares of the integers

//  Created by Anoja Rajalakshmi on 9/18/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int low, int high, int arr[])
{
    int pivot = arr[high];    // make pivot as last element
    int i = (low - 1);  // Index of smaller element
    
    for (int j = low; j < high; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot){
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); //bring pivot to proper position
    return (i + 1);
}

void quicksort(int p, int r, int arr[]){
    if(p < r){
        int q = partition(p,r,arr);
        quicksort(p, q-1, arr);
        quicksort(p+1, r, arr);
    }
    
}
int main(int argc, const char * argv[]) {
    int arr[] = {-3, -1, 2, 4}; // 9,1,4,16 //1,4,9,16
    int size = (sizeof(arr)/sizeof(arr[0]));
    
    for(int i=0; i < size;i++)
        arr[i] *= arr[i];
    
    quicksort(0,size-1,arr);
    for(int i=0; i < size;i++)
        printf("%d ",arr[i]);
    return 0;
}
