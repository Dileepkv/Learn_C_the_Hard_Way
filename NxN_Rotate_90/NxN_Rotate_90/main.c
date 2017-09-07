//
//  main.c
//  NxN_Rotate_90
//  Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

//  Created by Anoja Rajalakshmi on 9/7/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>

void print_array(int size, int arr[size][size]){
    /* output each array element's value */
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < size; col++ ) {
            printf("%d\t",arr[row][col] );
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int arr[3][3] = {
        {7,8,9},
        {4,5,6},
        {1,2,3}
        
    };
    const int N = sizeof(arr)/ sizeof(arr[0]);
    //int row = sizeof(arr) / sizeof(result[0]);
    //int column = sizeof(arr[0])/row;
    print_array(N,arr);
    int new[N][N];
    
    for(int y=0; y <= N-1; y++){
        for(int x=0; x <= N-1 ;x++){
            new[(N-1)-y][x] = arr[x][y];
           }
    }
    print_array(N,new);
    return 0;
}

