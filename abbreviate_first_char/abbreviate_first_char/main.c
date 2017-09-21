//
//  main.c
//  abbreviate_first_char
//
//  Created by Anoja Rajalakshmi on 9/18/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
char * abbreviate(char *str,int len){
    char *ab= (char *)malloc(sizeof(char)*len);
    ab[0]=str[0];
    int ab_index=1;
    for(int i=0;i<len;i++){
        if(str[i] == ' ')
            ab[ab_index++] = str[i+1];
    }
    return ab;
}
int main(int argc, const char * argv[]) {
    char str[] = "i am a hacker";
    printf("%s\n",abbreviate(str,strlen(str)));
    return 0;
}
