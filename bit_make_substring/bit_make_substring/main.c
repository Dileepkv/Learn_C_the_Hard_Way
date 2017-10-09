//
//  main.c
//  bit_make_substring
//  Given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to set all bits between i and j in N equal to M (e.g., M becomes a substring of N located at i and starting at j).

//  Created by Anoja Rajalakshmi on 10/1/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
int updateBits(int n, int m, int i, int j) {
    int max = ~0; // ffffffff
    // 1’s through position j, then 0’s
    int left = max - ((1 << j) - 1); //ffffffff - 3f = ffffffc0
    // 1’s after position i
    int right = ((1 << i) - 1); //3
    // 1’s, with 0s between i and j
    int mask = left | right; //ffffffc3
    // Clear i through j, then put m in there
    return (n & mask) | (m << i);
}
int main(int argc, const char * argv[]) {
    //Input: N = 100 0000 0000, M = 10101, i = 2, j = 6
    printf("%x \n",updateBits(0x0400,0x0015,2,6));  //100 0101 0100
    return 0;
}
