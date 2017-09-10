//  main.c
//  find_N_To_LastNode
//
//  Created by Anoja Rajalakshmi on 9/9/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node* next;
};

struct Node * findNToLastNode(struct Node *head, int N ){
    struct Node *current, *behind;
    current = head;
    for(int i = 0; i < N; i++ ) {
        if( current->next ) {
            current = current->next;
        } else
            return NULL;// Length of the list is less than N
    }
    behind = head;
    while( current->next ) {
        current = current->next;
        behind = behind->next;
    }
    return behind;
 }

void insert(struct Node** node, int new_value){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));// allocate node
    new_node->value  = new_value; // put in the data
    new_node->next = (*node);// link the old list off the new node
    (*node) = new_node;// move the head to point to the new node
}
int main(int argc, const char * argv[]) {
    struct Node* head = NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    struct Node* Nth = findNToLastNode(head, 2);
    while(Nth!=NULL){
        printf("%d->",Nth->value);
        Nth = Nth->next;
    }
    return 0;
}

