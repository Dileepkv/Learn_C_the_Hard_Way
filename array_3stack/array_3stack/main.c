//
//  main.c
//  array_3stack
//
//  Created by Anoja Rajalakshmi on 9/11/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>


int stack_size = 20;
int stack[100];
int *stack_pointer;//[3] = { -1, -1, -1};
int stack_no=0;

void push_stack(int stack_num, int value){
    if(stack_num > stack_no || stack_num < 0) return;
    int index = stack_num * stack_size + stack_pointer[stack_num] + 1;
    //printf("PUSH index= %d, sp= %d\n",index,stack_pointer[stack_num]);
    stack_pointer[stack_num]++;
    stack[index] = value;
}

void pop_stack(int stack_num){
    if(stack_num > stack_no|| stack_num < 0) return;
    int index = stack_num * stack_size + stack_pointer[stack_num];
    int value = stack[index];
    //printf("POP index= %d, sp= %d\n",index,stack_pointer[stack_num]);
    stack_pointer[stack_num]--;
    printf("\nPopped Value from Stack %d is %d\n", stack_num, value);
}


void print_stack(){
    for(int i = 0; i < stack_no; ++i){
        printf("Stack %d contains ", i);
        for(int j = 0; j <= stack_pointer[i]; ++j){
            printf("%d ", stack[i * stack_size + j]);
        }
        printf("\n");
    }
}

int main(){
    
    printf("Enter the stack number:"); //4
    scanf("%d",&stack_no);
    stack_pointer = (int *)malloc(stack_no * sizeof(int));
    
    
    push_stack(2, 1);
    push_stack(2, 2);
    push_stack(2, 3);
    push_stack(2, 4);
    push_stack(3, 2);
    push_stack(3, 3);
    push_stack(1, 4);
    push_stack(1, 5);
    push_stack(3, 6);
    push_stack(0, 7);
    print_stack();
    
    pop_stack(2);
    pop_stack(2);
    pop_stack(2);
    print_stack();
    
    pop_stack(2);
    pop_stack(3);
    print_stack();
    push_stack(0, 8);
    push_stack(0, 3);
    push_stack(1, 32);
    pop_stack(2);
    print_stack();
    
    return 0;
}
