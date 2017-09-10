//
//  main.c
//  linkedList_Addition
//  You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1’s digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.
//  EXAMPLE
//  Input: (3 -> 1 -> 5) + (5 -> 9 -> 2)
//  Output: 8 -> 0 -> 8
//  Created by Anoja Rajalakshmi on 9/9/17.
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

int add_digits(int d1,int d2){
    static int carry=0;
    int sum = d1 + d2 + carry;
    if(sum/10) carry=1;
    else carry = 0;
    return (sum % 10);
}

struct Node * add(struct Node *first, struct Node *second){
    struct Node  *prev=NULL; //to iterate result linklist
    struct Node  *res=NULL; // pointer to start of result linklist
    struct Node  *temp; // new node to fill data and copy to result linklist
    while(first!=NULL || second!=NULL){
        //create memory for a result node
        temp = (struct Node*) malloc(sizeof(struct Node));// allocate node
        temp->value = add_digits((first? first->value: 0), (second? second->value: 0));
        temp->next = NULL;
        
        if(res) prev -> next = temp;// if this is not the first result node
        else res = temp; // if this is first node
        prev = temp; //move the pointer of result linklist ahead
        if(first) first=first->next;
        if (second) second=second->next;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    struct Node  *head1, *head2, *result;
    insert(&head1,5);
    insert(&head1,1);
    insert(&head1,3);
    insert(&head1,5);
    
    insert(&head2,2);
    insert(&head2,9);
    insert(&head2,5);
    print_list(head1);
    print_list(head2);
    
    result = add(head1,head2);
    printf("Resultant:\n");
    print_list(result);
    return 0;
}
