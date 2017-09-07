//
//  main.c
//  Anagram_check - method to decide if two strings are anagrams or not.
//
//  Created by Anoja Rajalakshmi on 9/6/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include "quicksort.h"

bool anagram_check(char * str1,char * str2){
    if(strlen(str1)!=strlen(str2))
        return false;
    int size = strlen(str1);
    quickSort(str1,0,size-1);
    quickSort(str2,0,size-1);
    printf("%s %s\n",str1,str2);
    return(*str1 == *str2);
}

int main(int argc, const char * argv[]) {
    char str1[] = "cinema";
    char str2[] = "iceman";
    
    if(anagram_check(str1,str2))
        printf(" The two strings are Anagrams\n");
    else
        printf("Not same\n");
    return 0;
}
