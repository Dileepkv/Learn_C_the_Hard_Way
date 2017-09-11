//
//  main.c
//  array-modification
//  Create a function that modifies a character array or string - convert all the letter to uppercase and change all the spaces to underlines

//  Created by Anoja Rajalakshmi on 9/11/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    char array[20];
    printf("Enter the string:");
    fgets(array, 20,stdin);
    printf("%s",array);
    return 0;
}
