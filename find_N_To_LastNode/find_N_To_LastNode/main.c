//
//  main.c
//  find_N_To_LastNode
//
//  Created by Anoja Rajalakshmi on 9/9/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.

#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct Node
{
    int value;
    struct Node* next;
};

int main(int argc, const char * argv[]) {
    struct Node *temp,*list;
    temp = (struct Node *)malloc(sizeof(struct Node));
    list = temp;
    temp->value = (int)3;
    temp->next = (struct Node *)malloc(sizeof(struct Node));
    temp= temp->next;
    temp->value = (int)5 ;
    temp->next= NULL;
    
    while(list){
        printf("%d\t",list->value);
        list = list->next;
    }
    return 0;
}

