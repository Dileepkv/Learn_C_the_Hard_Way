//
//  main.c
//  count_set_bits
//  Given an integer, print the next smallest and next largest number that have the same number of 1 bits in their binary representation.

//  Created by Anoja Rajalakshmi on 9/22/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
// Function to get no of set bits in binary representation of positive integer n
unsigned int countSetBits(unsigned int n){
    unsigned int count = 0;
    while (n){
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int next_smallest_no(int number){
    int set_no = countSetBits(number);
    for(int i=number-1;;i--){
        if(countSetBits(i)==set_no)
            return i;
    }
    return -1;
}
int next_largest_no(int number){
    int set_no = countSetBits(number);
    for(int i=number+1;;i++){
        if(countSetBits(i)==set_no)
            return i;
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    int number = 4;
    printf("Number of set bits is %d\n",countSetBits(number));
    printf("Next smallest is %d\n",next_smallest_no(number));
    printf("Next largest is %d\n",next_largest_no(number));
    return 0;
}
