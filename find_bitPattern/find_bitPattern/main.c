//
//  main.c
//  find_bitPattern
//
//  Created by Anoja Rajalakshmi on 9/14/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    
    unsigned int number = 0xa2;
    unsigned int pattern = 0x02;
    unsigned int pattern_mask = 0x03;
    
    int count = 0;
    while(number > 0) {
        
        if( !((number ^ pattern) & pattern_mask) ) {
            ++count;
            //printf("%x\n", number);
        }
        
        number >>= 1;
        
    }
    
    printf("\ncount:  %d\n", count);
    
    return 0;
}
