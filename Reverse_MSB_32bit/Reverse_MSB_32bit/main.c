//
//  main.c
//  Reverse_MSB_32bit
//  C program to encode bits in a 32-bit number such that, most significant 16 bits should be reversed but lower 16 bits should be untouched. Generalize this to any number of bits.

//  Created by Anoja Rajalakshmi on 9/14/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//
#define getBit(X, bit) ((X>>bit)&1)

// Function to reverse bits of num 
unsigned int encodeBits(unsigned int num)
{
    unsigned int NO_OF_BITS = sizeof(num) * 8;
    unsigned int encode_num = 0, i, temp1,temp2;
    
    for (i = 0; i < NO_OF_BITS/2; i++)
    {
        encode_num |= (num & (1 << i));
    }
    
    for (i = (NO_OF_BITS/2); i < NO_OF_BITS; i++)
    {
        temp1 = (num & (1 << i));
        temp2 = (num & (1 << ((NO_OF_BITS - 1) - i)));
        
        encode_num |= (num & (1 << ((NO_OF_BITS - 1) - i)));
        
    }
    
    return encode_num;
}

/* Driver function to test above function */
int main()
{
    unsigned int x = 4039831754;  //F0CAF0CA
    printf("%x \n", x);
    printf("%x \n", encodeBits(x));  //530FF0CA
    return 0;
}
