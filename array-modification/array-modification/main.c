//
//  main.c
//  array-modification
//  Create a function that modifies a character array or string - convert all the letter to uppercase and change all the spaces to underlines

//  Created by Anoja Rajalakshmi on 9/11/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
#include <ctype.h> 
void change_to_upper(char * arr){
    int i=0;
    while(arr[i]){
        arr[i] = toupper(arr[i]);
        i++;
    }
}

int main(int argc, const char * argv[]) {
    char array[20];
    printf("Enter the string:");
    fgets(array, 20,stdin);
    
    change_to_upper(array);
    printf("\n%s",array);
    return 0;
}
