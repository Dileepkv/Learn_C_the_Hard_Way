//
//  main.c
//  my_memcpy
//
//  Created by Anoja Rajalakshmi on 9/18/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
void my_memcpy(char *src,char *dest,unsigned long len){
    while(len){
        *dest++ = *src++;
        len--;
    }
    dest[len]=0;
}
int main(int argc, const char * argv[]) {
    char *s1 = "wert";
    char s2[0];
    my_memcpy(s1,s2,(unsigned long)strlen(s1));
    printf("%s\n",s2);
    return 0;
}
