//
//  main.c
//  bit_required_to_convert
/*
    Write a function to determine the number of bits required to convert integer A to integer B.
    Input: 31, 14
    Output: 2
 */
//  Created by Anoja Rajalakshmi on 9/22/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
//Method 1: Checking bit by bit
int bits_required(int n1,int n2){
    int count=0;
    while(n1 || n2){
        if((n1&1) != (n2&1)) count++;
        n1 >>= 1;
        n2 >>= 1;
    }
    return count;
}
//Method 2: Using XOR
int bits_req(int n1,int n2){
    int count = 0;
    for (int c = n1 ^ n2; c != 0; c = c >> 1) {
        count += c & 1;
        }
    return count;
}
int main(int argc, const char * argv[]) {
    int num1 = 1;
    int num2 = 6;
    printf("Method 1: %d\n",bits_required(num1,num2));
    printf("Method 2: %d\n",bits_req(num1,num2));
    return 0;
}
