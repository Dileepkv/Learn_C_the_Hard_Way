//
//  main.c
//  swap_pointers_without_temp
//
//  Created by Anoja Rajalakshmi on 9/15/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.

#include <stdio.h>
void swap(int *xp, int *yp)
{
    if (xp == yp) // Check if the two addresses are same
        return;
    *xp = *xp + *yp;
    *yp = *xp - *yp;
    *xp = *xp - *yp;
}
int main()
{
    int x = 10;
    int y = 11;
    swap(&x, &y);
    printf("After swapping: x = %d,y = %d\n", x,y);
    return 0;
}
