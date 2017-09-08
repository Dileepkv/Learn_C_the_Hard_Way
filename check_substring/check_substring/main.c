//
//  main.c
//  check_substring -- Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring (i.e., “waterbottle” is a rotation of “erbottlewat”).

//  Created by Anoja Rajalakshmi on 9/8/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.

#include <stdio.h>
#include <string.h>
#include <stdlib.h> //for free()

int isSubstring(char *str1, char *str2)
{
    if(strlen(str1)!=strlen(str2))
        return 0;
    int size = strlen(str1);
    // Create a temp string with value str1.str1
    char *temp   = (char *)malloc(sizeof(char)*(size*2 + 1));
    temp = strcat(temp,str1);
    temp = strcat(temp,str1); //wat'erbottlewat'erbottle
    
    void *ptr = strstr(temp, str2); //strstr returns NULL if the second string is NOT a substring of first string
    free(temp);
    
    if(ptr!=NULL) return 1;
    else return 0;
}
int main(int argc, const char * argv[]) {
    char str1[] = "waterbottle";
    char str2[] = "erbottlewat";
    if(isSubstring(str1,str2))
        printf("%s is a rotation of %s\n",str1,str2);
    else
        printf("%s is not a rotation of %s\n",str1,str2);
    return 0;
}
