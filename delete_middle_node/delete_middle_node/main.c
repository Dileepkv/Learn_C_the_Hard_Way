//
//  main.c
//  delete_middle_node
//  copy the data from the next node to the node to be deleted and delete the next node
//  Created by Anoja Rajalakshmi on 9/9/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

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

void delete_node(struct Node *node_ptr){
    struct Node *temp = node_ptr->next;
    node_ptr->value  = temp->value;
    node_ptr->next   = temp->next;
}

void print_list(struct Node *list){
    struct Node *node = list;
    while(node!=NULL){
        printf("%d -> ",node->value);
        node=node->next;
    }
    printf("NULL\n");
}
int main(int argc, const char * argv[]) {
    struct Node* head, *temp;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    temp=head;
    insert(&head,4);
    insert(&head,5);
    
    print_list(head);
    
    delete_node(temp); //deleting random node using temp
    print_list(head);
    
    delete_node(head);
    print_list(head);
    
    
    return 0;
}
