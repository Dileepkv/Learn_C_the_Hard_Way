//
//  main.c
//  occurence_0_to_9
//  a program that prints the number of times each number 0-9 appears on an array
//  Created by Anoja Rajalakshmi on 9/18/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int arr[] = {1,2,3,4,5,6,7,8,0,3,5,7,8,2,2,3,4,5,6,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int *num_arr=(int *)calloc(10,sizeof(int));
    for (int i=0;i<size;i++){
        int index=arr[i];
        num_arr[index]++;
    }
    for (int i=0;i<10;i++){
        printf("%d->%d\n",i,num_arr[i]);
    }
    return 0;
}
