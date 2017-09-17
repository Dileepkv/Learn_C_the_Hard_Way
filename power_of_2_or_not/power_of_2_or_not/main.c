//
//  main.c
//  power_of_2_or_not - function that determines if a given variable is a power of 2 or not

//  Created by Anoja Rajalakshmi on 9/15/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

bool find_power(int num){
    for (int i=num; i>= 2;){
        if(i%2==0)
            i=i/2;
        else
            return false;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    int num= 262148;
    if(find_power(num))
        printf("%d is a power of 2\n",num);
    else
        printf("%d is not a power of 2\n",num);
    return 0;
}
