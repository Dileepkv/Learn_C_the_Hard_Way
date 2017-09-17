//
//  main.c
//  my_atoi
//
//  Created by Anoja Rajalakshmi on 9/17/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
int my_atoi(char * str){
    int number = 0;
    int neg_flag=0;
    int len = strlen(str);
    for (int i=0;i<len;i++){
        if(str[i]>=48 && str[i]<=57)
            number=(10 * number)+(str[i]-48);
        else if(str[0]=='-')
            neg_flag=1;
        else
            return -1;
    }
    if(neg_flag) number= number * -1;
    return number;
}
int main(int argc, const char * argv[]) {
    char num[]="87509";
    printf("%d\n",my_atoi(num));
    return 0;
}
