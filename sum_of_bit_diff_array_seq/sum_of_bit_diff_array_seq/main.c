//
//  main.c
//  sum_of_bit_diff_array_seq
/*  Array { 1 3 5}
 
    Resultant Array
    {(1,3) (1,5) (1,1)
     (3,1) (3,5) (3,3)
     (5,1) (5,3) (5,5)}
    Sum of difference: 2+4+0+2+2+0+4+2+0 = 16
    Final Answer is 16
 */
//  Created by Anoja Rajalakshmi on 10/1/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    int arr[] = {2, 4, 8};
    int sum = 0;
    int size = sizeof(arr)/sizeof(arr[0]);
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            sum += abs(arr[i]-arr[j]);
        }
    }
    printf("%d \n",sum);
    return 0;
}
