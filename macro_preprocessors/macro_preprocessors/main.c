//
//  main.c
//  macro_preprocessors
//
//  Created by Anoja Rajalakshmi on 9/25/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
#define MIN(A,B) ((A<=B)?(A):(B))
int main(int argc, const char * argv[]) {
    int a[] = {5,1,12,3};
    int *p=a;
    printf("%d\n",MIN(*p++, *a));
    return 0;
}
