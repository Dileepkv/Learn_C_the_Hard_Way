//
//  main.c
//  Replace_0_MxN_matrix
//
//  Created by Anoja Rajalakshmi on 9/7/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

void print_array(int _row,int _col, int arr[_row][_col]){
    /* output each array element's value */
    for ( int row = 0; row < _row; row++ ) {
        for ( int col = 0; col < _col; col++ ) {
            printf("%d\t",arr[row][col] );
        }
        printf("\n");
    }
    printf("\n");
}
void init_bool_array(int _row,int _col, int arr[_row][_col]){
        for ( int row = 0; row < _row; row++ ) {
        for ( int col = 0; col < _col; col++ ) {
            arr[row][col]=0;
        }
    }
}


int main(int argc, const char * argv[]) {
    int arr[4][3] = {
        {2,8,0},
        {4,5,6},
        {1,0,7},
        {8,3,5}
        
    };
    int row = sizeof(arr) / sizeof(arr[0]);
    int col = sizeof(arr[0])/row;
    //printf("%d,%d",row,col);
    
    int is_zero[row][col];
    init_bool_array(row,col,is_zero);
    print_array(row,col,arr);
    //check for 0
    for(int i=0; i < row; i++){
        for(int j=0; j < col ;j++){
            if(arr[i][j]==0)
                is_zero[i][j]=1;
        }
    }
    print_array(row,col,is_zero);
    int r=0,c=0;
    
    for(int r=0; r < row; r++){
        for(int c=0; c < col ;c++){
            if(is_zero[r][c]){
                for(int i=0; i < row; i++){
                    arr[i][c]=0;
                }
                for(int j=0; j < col; j++){
                    arr[r][j]=0;
                }
            }
        }
    }
    
    print_array(row,col,arr);
    return 0;
}
