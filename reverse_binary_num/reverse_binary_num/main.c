//
//  main.c
//  reverse_binary_num: swap msb and lsb not considering leading zeros

//  Created by Anoja Rajalakshmi on 9/30/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
#define CHECK_BIT(num,bit) ((num & (0x01<<bit))!=0)
#define SET_BIT(num,bit)   (num |= (0x01<<bit))
#define CLEAR_BIT(num,bit) (num &= ~(0x01<<bit))

int main(int argc, const char * argv[]) {
    unsigned int num = -4; //0x0101;//0x5af3(odd) // 0xdaf3(even)
    int bit_count = 0;//length of binary representation for num
    int size = (sizeof(int)*8);
    for (int i=size-1;i>=0;i--){
        if(CHECK_BIT(num,i)!=0){
            bit_count = i+1;
            break;
        }
    }
    printf("%d \n",bit_count);
    int mid = (bit_count/2); // find mid point to split
    printf("mid %d \n",mid);
    unsigned int result = (num << (size-mid)); //shift LSB bits to MSB
    printf("%x \n",result);

    result >>= (size-bit_count); //Bring LSB bits to where MSB is placed, since leading zero is not considered
    printf("%x \n",result);
    if(bit_count%2==0) // if even
        result |= (num >> mid); // Shift MSB of num to LSB and OR with MSB
    else{   //if odd set of binary
        result |= (num>>(mid+1)); // Shift MSB of num to LSB and OR with MSB
        if(CHECK_BIT(num,mid)) // for mid value
            SET_BIT(result,mid);
    }
    printf("%x \n",result);
    return 0;
}
