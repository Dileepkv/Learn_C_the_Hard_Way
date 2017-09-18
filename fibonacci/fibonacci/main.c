//
//  main.c
//  fibonacci
//
//  Created by Anoja Rajalakshmi on 9/17/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
void print_fibonacci(int num){
    int p = 0;
    if(num==0){
        printf("%d",num);
        return;
    }
    else if(num==1){
        printf("0 1");
        return;
    }
    else{
        printf("0 1 1 ");
        for (int i=1;i<=num;i++){
            p = p+i;
            printf("%d ",p);
        }
    }
}
int main(int argc, const char * argv[]) {
    int n= 5; //0 1 1 2 3 5
    print_fibonacci(n);
    
    return 0;
}
