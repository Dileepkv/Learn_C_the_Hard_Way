//
//  main.c
//  Use_Static
//  A function that returns an array of the first five primes, that would be 2,3,5,7,11. Have the main function display those values.
//  Created by Anoja Rajalakshmi on 9/10/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.

#include <stdio.h>

int * prime_number(void){
    static int a[5] = {2,3,5,7,11};
    return a;
}

int main(int argc, const char * argv[]) {
    int * arr;
    int i=0;
    arr = prime_number();
    while (i<5){
        printf("%d ",arr[i]);
        i++;
    }
    return 0;
}
