//
//  main.c
//  reverse_linkedlist
/*  For 5 -> 10 -> 13, consider 10 as current, 5 prev and 13 next.
    13 = 10 -> next
    10 -> next = 5
    5 = 10
    10 = 13
*/
//  Created by Anoja Rajalakshmi on 9/15/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.

#include <stdio.h>

struct Node{
    int value;
    struct Node* next;
};

void insert(struct Node** node, int new_value){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));// allocate node
    new_node->value  = new_value; // put in the data
    new_node->next = (*node); // link the old list off the new node
    (*node) = new_node; // move the head to point to the new node
}
void print_list(struct Node *list){
    struct Node *node = list;
    while(node!=NULL){
        printf("%d -> ",node->value);
        node=node->next;
    }
    printf("NULL\n");
}
void reverse_list(struct Node **head){
    struct Node *current = *head;
    struct Node *prev = NULL;
    struct Node *next;
    while(current!=NULL){
        next = current-> next;
        current-> next = prev;
        prev = current;
        current = next;
    }
    *head=prev;
}
int main(int argc, const char * argv[]) {
    struct Node  *head1;
    insert(&head1,4);
    insert(&head1,10);
    insert(&head1,13);
    insert(&head1,67);
    insert(&head1,2);
    insert(&head1,9);
    print_list(head1);
    reverse_list(&head1);
    print_list(head1);
    
    return 0;
}
