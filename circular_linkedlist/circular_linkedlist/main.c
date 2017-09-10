//
//  main.c
//  circular_linkedlist
/*  Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.
    DEFINITION
    Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an earlier node, so as to make a loop in the linked list.
    
    EXAMPLE
    Input: A -> B -> C -> D -> E -> C [the same C as earlier]
    Output: C */
//  Created by Anoja Rajalakshmi on 9/10/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//


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
struct Node * check_circular(struct Node * head){
    struct Node * current,*next,*corrupt;
    current = head;
    next = head;
    while (current){
        while (next){
            next= next->next;
            if(current->value == next->value){
                corrupt=next;
                corrupt->next=NULL;
                return corrupt;
            }
        }
        current = current->next;
    }
    return current;
}

int main(int argc, const char * argv[]) {
    struct Node* head, *circ;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);
    insert(&head,3);
    
    print_list(head);
    circ=check_circular(head);
    printf("Corrupt node is %d \n",circ->value);
    //print_list(circ);
    return 0;
}
