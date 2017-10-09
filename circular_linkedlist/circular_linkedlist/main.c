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
void removeLoop(struct Node *, struct Node *);
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
int check_circular(struct Node * list){
    struct Node  *slow_p = list, *fast_p = list;
    
    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        
        if (slow_p == fast_p){// If slow_p and fast_p meet at some point then there is a loop
            removeLoop(slow_p, list);
            return 1;
        }
    }
    return 0;
}

void removeLoop(struct Node *loop_node, struct Node *head){
    struct Node *ptr1;
    struct Node *ptr2;
    
    /* Set a pointer to the beging of the Linked List and
     move it one by one to find the first node which is
     part of the Linked List */
    ptr1 = head;
    while (1)
    {
        /* Now start a pointer from loop_node and check if it ever
         reaches ptr2 */
        ptr2 = loop_node;
        while (ptr2->next != loop_node && ptr2->next != ptr1)
            ptr2 = ptr2->next;
        
        /* If ptr2 reahced ptr1 then there is a loop. So break the
         loop */
        if (ptr2->next == ptr1)
            break;
        
        /* If ptr2 did't reach ptr1 then try the next node after ptr1 */
        ptr1 = ptr1->next;
    }
    
    /* After the end of loop ptr2 is the last node of the loop. So
     make next of ptr2 as NULL */
    ptr2->next = NULL;
}
struct Node *newNode(int key)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->value = key;
    temp->next = NULL;
    return temp;
}

/* Drier program to test above function*/
int main()
{
    
    struct Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);
    
    // Create a loop for testing 6->3->4->5->6->3
    head->next->next->next->next->next->next = head->next->next;
    //print_list(head);
    check_circular(head);
    print_list(head);
    return 0;
}
