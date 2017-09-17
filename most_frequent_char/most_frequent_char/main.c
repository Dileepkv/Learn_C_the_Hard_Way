//
//  main.c
//  most_frequent_char - Return the most frequent character in a string
//
//  Created by Anoja Rajalakshmi on 9/15/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    char str[]= "pineapple";
    int max_index=-1;
    int size = strlen(str);
    int *array = malloc(size*sizeof(int));
    memset(array, 0, size*sizeof(int));
    
    for(int i=0; i<size;i++){
        for(int j=i;j<size;j++){
            if(str[i]==str[j])
                array[i]++;
            }
    }
    
    for(int i=0; i<size;i++){
        max_index = array[max_index] < (array[i]) ? i : max_index;
    }
    printf("Most frequent char is %c \n", str[max_index]);
    return 0;
}
