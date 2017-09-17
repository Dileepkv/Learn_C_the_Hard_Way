//
//  main.c
//  first_non-occuring_char
//
//  Created by Anoja Rajalakshmi on 9/15/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include<stdlib.h>
#include<stdio.h>
#define NO_OF_CHARS 256

/* Returns an array of size 256 containg count
 of characters in the passed char array */
int *getCharCountArray(char *str)
{
    int *count = (int *)calloc(sizeof(int), NO_OF_CHARS);
    int i;
    for (i = 0; *(str+i);  i++)
        count[*(str+i)]++;
    return count;
}

/* The function returns index of first non-repeating
 character in a string. If all characters are repeating
 then returns -1 */
int firstNonRepeating(char *str)
{
    int *count = getCharCountArray(str);
    int index = -1, i;
    
    for (i = 0; *(str+i);  i++){
        //printf("count[%c] = %d \n",*(str+i),count[*(str+i)]);
        if (count[*(str+i)] == 1){
            index = i;
            break;
        }
    }
    
    free(count); // To avoid memory leak
    return index;
}

int main()
{
    char str[] = "pepperminter";
    int index =  firstNonRepeating(str);
    if (index == -1)
        printf("Either all characters are repeating or string is empty");
    else
        printf("First non-repeating character is %c", str[index]);
    
    return 0;
}
