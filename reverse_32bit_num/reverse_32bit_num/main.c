//
//  main.c
//  reverse_32bit_num
//
//  Created by Anoja Rajalakshmi on 9/24/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>

uint32_t reverseBits(uint32_t n) {
    n = ((n >> 1) & 0x55555555) | ((n << 1) & 0xaaaaaaaa);
    //printf("%x\n",n);
    n = ((n >> 2) & 0x33333333) | ((n << 2) & 0xcccccccc);
    //printf("%x\n",n);
    n = ((n >> 4) & 0x0f0f0f0f) | ((n << 4) & 0xf0f0f0f0);
    //printf("%x\n",n);
    n = ((n >> 8) & 0x00ff00ff) | ((n << 8) & 0xff00ff00);
    //printf("%x\n",n);
    n = ((n >> 16) & 0x0000ffff) | ((n << 16) & 0xffff0000);
    return n;
}
uint16_t reverseBit(uint16_t n){
    n = ((n>>1)& 0x5555) | ((n<<1)&0xaaaa);
    n = ((n>>2)& 0x3333) | ((n<<2)&0xcccc);
    n = ((n>>4)& 0x0f0f) | ((n<<4)&0xf0f0);
    n = ((n>>8)& 0x00ff) | ((n<<8)&0xff00);
    return n;
}
int main(int argc, const char * argv[]) {
    printf("%x\n",reverseBits(0x20abcdef));
    printf("%x\n",reverseBit(0xabcd));
    return 0;
}
