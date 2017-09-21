//
//  main.c
//  Endianness
//  Convert Big endian to little endian

//  Created by Anoja Rajalakshmi on 9/18/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
unsigned int convert_endianness(unsigned int x)
{
    return (((x>>24) & 0x000000ff) | //000000aa
            ((x>> 8) & 0x0000ff00) | //0000bb00
            ((x<< 8) & 0x00ff0000) | //00cc0000
            ((x<<24) & 0xff000000)); //dd000000
}

int main(int argc, const char * argv[]) {
    unsigned int i = 1;
    if ((char*)&i)
        printf("Little endian\n");
    else
        printf("Big endian\n");
    
    unsigned int num = convert_endianness((unsigned int)0XAABBCCDD);
    printf("Converted:%x \n",num);
    num = convert_endianness(num);
    printf("Converting back: %x \n",num);

    return 0;
}
