//
//  main.c
//  sort_string
//
//  Created by Anoja Rajalakshmi on 9/11/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.

#include <stdio.h>
#include <stdlib.h>

int compare(const void* p1, const void* p2);

int main(int argc, const char * argv[]) {
    char string[20] = "thin  gacdbt ugtuyh";
    printf("String before sorting:\n%s\n",string);
    qsort(string,strlen(string),sizeof(char),compare);
    printf("String after sorting:\n%s\n",string);
    return 0;
}
int compare(const void *a,const void *b){
    return (*(char *)a - *(char *)b);
}
