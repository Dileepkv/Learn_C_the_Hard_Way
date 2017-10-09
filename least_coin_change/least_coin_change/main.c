//
//  main.c
//  least_coin_change
//  Find the least number of coins required that can make any change from 1 to 99 cents

//  Created by Anoja Rajalakshmi on 9/19/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
int least_change(int * current){
    int coin_type[4]={25,10,5,1};
    int count  =0,i=0;
    while(*current){
        while(coin_type[i]<=*current){
            count ++;
            *current -= coin_type[i];
        }
        i++;
    }
    printf("Value %d coin %d\n",*current,count);
    return count;
}
int main(int argc, const char * argv[]) {
    int min = 99;
    int i = 0;
    for(int i=1;i<=99;i++){
        int count=least_change(&i);
        if(min>count)
            min=count;
    }
    printf("Minimum number of coins required: %d\n",min);
    return 0;
}
