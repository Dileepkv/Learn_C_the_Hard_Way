//
//  main.c
//  binary_tree_implementation
//
//  Created by Anoja Rajalakshmi on 9/16/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

struct node* insert_node(struct node* node, int data) {
    // 1. If the tree is empty, return a new, single node
    if (node == NULL) {
        node = newNode(data);
        return (node);
    }
    else {
        // 2. Otherwise, recur down the tree
        if (data <= node->data) node->left = insert_node(node->left, data);
        else node->right = insert_node(node->right, data);
        
        return(node); // return the (unchanged) node pointer
    } 
}
/*
 Given a binary tree, return true if a node
 with the target data is found in the tree. Recurs
 down the tree, chooses the left or right
 branch by comparing the target to each node.
 */
static int search(struct node* node, int target) {
    // 1. Base case == empty tree
    // in that case, the target is not found so return false
    if (node == NULL) {
        return(false);
    }
    else {
        // 2. see if found here
        if (target == node->data) return(true);
        else {
            // 3. otherwise recur down the correct subtree
            if (target < node->data) return(search(node->left, target));
            else return(search(node->right, target));
        } 
    } 
}

int size(struct node* node) {
    if (node==NULL) {
        return(0);
    } else {
        return(size(node->left) + 1 + size(node->right));
    }
}
int maxDepth(struct node* node) {
    if (node==NULL) {
        return(0);
    }
    else {
        // compute the depth of each subtree
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        // use the larger one
        if (lDepth > rDepth) return(lDepth+1);
        else return(rDepth+1);
    } 
}
int minValue(struct node* node) {
    struct node* current = node;
    // loop down to find the leftmost leaf
    while (current->left != NULL) {
        current = current->left;
    }
    return(current->data);
}

void print_inorder(struct node* node) {
    if (node!=NULL) {
        print_inorder(node->left);
        printf("%d ",node->data);
        print_inorder(node->right);
    }
}

void print_postorder(struct node* node) {
    if (node==NULL)  return;
    else {
        print_postorder(node->left);
        print_postorder(node->right);
        printf("%d ",node->data);
    }
}

int main(int argc, const char * argv[]) {
    struct node* root =NULL;
    root = newNode(10);
    root->left = newNode(7);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(8);
    root->right->left = newNode(12);
    root->right->right = newNode(20);
    root->right->right->right = newNode(35);
    printf("Search status of %d = %d\n",20,search(root,20));
    printf("Number of nodes = %d\n",size(root));
    printf("Max Depth of tree = %d\n",maxDepth(root));
    printf("Min Value of tree = %d\n",minValue(root));
    print_inorder(root);//increasing order
    printf("\n");
    print_postorder(root); //bottom-up level traversal
    return 0;
}
