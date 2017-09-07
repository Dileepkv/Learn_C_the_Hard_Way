//
//  main.c
//  Reverse_String
//
//  Created by Anoja Rajalakshmi on 9/6/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
void reverse(char *str) {
    char * end = str;
    //printf("%d\n",end);
    char tmp;
    if (str) {
        while (*end) {
            ++end;
            }
        //printf("%d\n",end);
        --end;
        while (str < end) {
            tmp = *str;
            *str++ = *end;
            *end-- = tmp;
            }
        }
    }

int main(int argc, const char * argv[]) {
    char array[20]= "abcde";
    reverse(array);
    printf("%s\n",array);
    return 0;
}
