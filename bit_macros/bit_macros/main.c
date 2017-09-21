//
//  main.c
//  bit_macros
//
//  Created by Anoja Rajalakshmi on 9/18/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
#define CHECK_BIT(number,bit) (number & (1<<bit))!=0
#define SET_BIT(number,bit) (number |= (1<<bit))
#define CLEAR_BIT(number,bit) (number &= ~(1<<bit))
#define IS_ODD(number) ((number & 0X01)!=0)
int main(int argc, const char * argv[]) {
    int i=0x15;
    printf("%x \n",i);
    printf("%x \n",CHECK_BIT(i,4));
    SET_BIT(i, 5);
    printf("%x \n",i);
    CLEAR_BIT(i, 5);
    printf("%x \n",i);
    printf("%x \n",IS_ODD(4));
    return 0;
}
