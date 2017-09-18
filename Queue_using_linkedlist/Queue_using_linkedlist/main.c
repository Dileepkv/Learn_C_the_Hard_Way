//
//  main.c
//  Queue_using_linkedlist
//  implement a queue/fifo with push/pop functionality using linked list
//  front / rear /
//  Created by Anoja Rajalakshmi on 9/15/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>

struct Node{
    int value;
    struct Node *next;
}*front,*rear;

void enqueue(int value){
    struct Node * new = (struct Node *)malloc(sizeof(struct Node));
    new -> value = value;
    new -> next = NULL;
    if(front == NULL)
        front = rear = new;
    else{
        rear->next = new;
        rear = new;
    }
}
void display_queue(){
    if(front==NULL)
        printf("Empty Queue");
    struct Node *temp = front;
    while(temp){
        printf("%d ",temp->value);
        temp=temp->next;
    }
}
void delete(){
    if(front == NULL)
        printf("\nEmpty Queue\n");
    else{
        struct Node *temp = front;
        front= front->next;
        printf("\nDeleted Node is %d\n",temp->value);
    }
}
int main(int argc, const char * argv[]) {
    delete();
    enqueue(45);
    enqueue(41);
    enqueue(12);
    enqueue(29);
    display_queue();
    delete();
    delete();
    delete();
    enqueue(20);
    enqueue(25);
    display_queue();
    delete();
    delete();
    display_queue();
    return 0;
}
