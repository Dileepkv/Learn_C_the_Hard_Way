//
//  main.c
//  Stack_using_linkedlist
//
//  Created by Anoja Rajalakshmi on 9/12/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//
// C program for linked list implementation of stack

#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
typedef struct StackNode{
    int data;
    struct StackNode* next;
}StackTop;

void push(StackTop **top, int data){
    StackTop *newTop = (StackTop *) malloc(sizeof(struct StackNode));
    newTop->data = data;
    if(top == NULL)
        newTop->next = NULL;
    else
        newTop->next = *top;
    
    *top = newTop;
    printf("%d pushed to stack\n", data);
}

int pop(StackTop ** top){
    if (*top==NULL){
        printf("Stack is Empty!!!\n");
        return -1;
    }
    StackTop *temp = *top;
    *top = (*top)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek(StackTop *top){
    if (top==NULL)
        return -1;
    return top->data;
}

int main(){
    StackTop *top = NULL;
    pop(&top);
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    
    printf("%d popped from stack\n", pop(&top));
    printf("%d popped from stack\n", pop(&top));
    printf("%d popped from stack\n", pop(&top));
    printf("%d popped from stack\n", pop(&top));
    printf("Top element is %d\n", peek(top));
    
    return 0;
}
