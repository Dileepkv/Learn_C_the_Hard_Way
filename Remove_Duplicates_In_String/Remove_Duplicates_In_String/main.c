//
//  main.c
//  Remove_Duplicates_In_String
//  C program to remove duplicates, the order of
//  characters is not maintained in this program

//  Created by Anoja Rajalakshmi on 9/6/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.


# include <stdio.h>
# include <stdlib.h>
# include "quicksort.h"
/* Function to remove duplicates in a sorted array */
char *removeDupsSorted(char *str);

/* Function removes duplicate characters from the string
   and work in-place and fills null characters
   in the extra space left */
char *removeDups(char *str)
{
    int len = strlen(str);
    quickSort(str, 0, len-1);
    return removeDupsSorted(str);
}

/* Function to remove duplicates in a sorted array */
char *removeDupsSorted(char *str)
{
    int res_ind = 1, ip_ind = 1;
    
    /* In place removal of duplicate characters*/
    while (*(str + ip_ind))
    {
        if (*(str + ip_ind) != *(str + ip_ind - 1))
        {
            *(str + res_ind) = *(str + ip_ind);
            res_ind++;
        }
        ip_ind++;
    }
    
    *(str + res_ind) = '\0';// Removing extra chars after string
    return str;
}

int main()
{
    char str[] = "afbaceccddaga";
    printf("%s", removeDups(str));
    getchar();
    return 0;
}

