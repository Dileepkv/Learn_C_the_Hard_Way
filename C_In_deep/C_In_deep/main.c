//
//  main.c
//  C_In_deep
//
//  Created by Anoja Rajalakshmi on 8/28/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//
#include <stdio.h>
int main()
{
    int x = 0x55, y = 0x00;
    int mask = 0xFF;
    // Code to swap 'x' and 'y'
   /* x = x + y;  // x now becomes 15
    y = x - y;  // y becomes 10
    x = x - y;  // x becomes 5
    */
    y=x ^ mask;
        printf("After Swapping: x = %x, y = %x", x, y);
    
    return 0;
}
