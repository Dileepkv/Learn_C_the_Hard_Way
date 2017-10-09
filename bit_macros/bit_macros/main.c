//
//  main.c
//  bit_macros
//
//  Created by Anoja Rajalakshmi on 9/18/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>

#define CHECK_BIT(num,bit) ((num & (1<<bit)) != 0)
#define SET_BIT(num,bit) (num |= (1<<bit))
#define CLEAR_BIT(num,bit) (num &= ~(1<<bit))
#define IS_ODD(num) ((num & 0X01)!=0)
#define POWER_OF_TWO(num) ((num & (num-1)) == 0)
#define SWAP_ALT_BITS(num) ( ((num & 0xaaaaaaaa) >> 1) | ((num & 0x55555555) << 1) ) //odd and even bits

int main(int argc, const char * argv[]) {
    int i=0x15;
    int j=4;
    //printf("%d \n",sizeof(int));
    for (int i=(sizeof(int)*8);i>=0;i--)
        //printf("%d",CHECK_BIT(0xFF00,i));
        if(CHECK_BIT(0xFF00,i)==CHECK_BIT(0xFF00,(sizeof(int)*8)-1)) printf("jbjb");
    SET_BIT(i, 5);
    printf("\n %x \n",i);
    CLEAR_BIT(i, 5);
    printf("%x \n",i);
    printf("%x \n",IS_ODD(4));
    printf("%x \n",POWER_OF_TWO(5));
    printf("%x \n",SWAP_ALT_BITS(0b00010001));
    return 0;
}
