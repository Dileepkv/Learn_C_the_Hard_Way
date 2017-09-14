//
//  main.c
//  determine_endiness
//  A character pointer c is pointing to an integer i. Since size of character is 1 byte when the character pointer is de-referenced it will contain only first byte of integer. If machine is little endian then *c will be 1 (because last byte is stored first) and if machine is big endian then *c will be 0.

//  Created by Anoja Rajalakshmi on 9/11/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//
#include <stdio.h>
int main()
{
    unsigned int i = 1;
    char *c = (char*)&i;
    if (*c)
        printf("Little endian");
    else
        printf("Big endian");
    //getchar();
    return 0;
}
