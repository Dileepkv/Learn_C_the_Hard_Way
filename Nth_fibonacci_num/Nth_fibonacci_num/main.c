//  main.c
//  Nth_fibonacci_num
//
//  Created by Anoja Rajalakshmi on 9/23/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>

int fib(int N){
    if(N<=1) return N;
    else if(N>1)
        return fib(N-1) + fib (N-2);
    else return -1;
}
int main(int argc, const char * argv[]) {
    printf("%d\n",fib(4));
    return 0;
}
