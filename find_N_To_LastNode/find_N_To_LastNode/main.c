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
/* Function to get the nth node from the last of a linked list*/
int findNthFromLast(struct Node* head, int n)
{
    int len = 0, i;
    struct Node *temp = head;
    //count the number of nodes in Linked List
    while (temp != NULL){
        temp = temp->next;
        len++;
    }
    // check if value of n is not more than length of the linked list
    if (len < n )
        return NULL;
    temp = head;
    
    //get the (n-len+1)th node from the begining
    for (i = 1; i < len-n+1; i++)
        temp = temp->next;
    return temp->value;
}
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
    insert(&head,21);
    insert(&head,58);
    insert(&head,31);
    insert(&head,45);
    insert(&head,80);
    insert(&head,13);
    insert(&head,63);
    insert(&head,98);
    int nth = 1;
    struct Node* Nth = findNToLastNode(head, nth);
    printf("\n%d-th to last\n",nth);

    while(Nth!=NULL){
        printf("%d->",Nth->value);
        Nth = Nth->next;
    }
    
    printf("\n%d-th from last is %d\n",nth,findNthFromLast(head,nth));
    return 0;
}

