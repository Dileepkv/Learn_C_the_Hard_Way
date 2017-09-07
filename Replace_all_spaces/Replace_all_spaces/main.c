//
//  main.c
//  Replace all spaces in a string with ‘%20’.
//
//  Created by Anoja Rajalakshmi on 9/6/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    char str[] = "i saw you";
    int size =strlen(str);
    int space_count=0;
    
    for (int i=0; i<size; i++){
        if(str[i]==32)
            space_count++;
    }
    int resize = size+(space_count*2);
    char result[resize];
    for (int i=0,p=0; i<size; i++){
        if(str[i]==32){
            result[p]='%';
            result[p+1]='2';
            result[p+2]='0';
            p=p+3;
        }
        else{
            result[p]=str[i];
            p++;
        }
    }
    result[resize]='\0';
    printf("%s\n",result);
    return 0;
}
