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

int hasPathSum(struct node* node, int sum) {
    // return true if we run out of tree and sum==0
    if (node == NULL) {
        return(sum == 0);
    }
    else {
        // otherwise check both subtrees
        int subSum = sum - node->data;
        return(hasPathSum(node->left, subSum) ||
               hasPathSum(node->right, subSum));
    } 
}
//print root to leaf paths
void print_paths(struct node* node, int path[], int pathLen){
    if (node==NULL) return;
    
    // append this node to the path array
    path[pathLen] = node->data;
    pathLen++;
    
    // it's a leaf, so print the path that led to here
    if (node->left==NULL && node->right==NULL) {
        for (int i=0; i<pathLen; i++) {
            printf("%d ",path[i]);
        }
        printf("\n");
    }
    else {
        // otherwise try both subtrees
        print_paths(node->left, path, pathLen);
        print_paths(node->right, path, pathLen);
    }
}

void mirror(struct node* node) {
    if (node==NULL)  return;
    else {
        // do the subtrees
        mirror(node->left);
        mirror(node->right);
        
        struct node * temp;
        temp = node->left;
        node->left =  node->right;
        node->right = temp;
    }
}
void doubleTree(struct node* node) {
    if (node==NULL)  return;
    else {
        doubleTree(node->left);
        doubleTree(node->right);
        struct node* temp;
        temp = node->left;
        node->left = newNode(node->data);
        node->left->left = temp;
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
    printf("\nIn Order:\n");
    print_inorder(root);//increasing order
    printf("\n\nPost Order: \n");
    print_postorder(root); //bottom-up level traversal
    printf("\n\nHas Root to Leaf Sum: %d\n",hasPathSum(root,37)); //10+15+12
    printf("\n\nRoot to Leaf Paths: \n");
    int path[size(root)];
    print_paths(root, path, 0);
    printf("\n\nMirror of the current tree: \n");
    mirror(root);
    print_postorder(root);
    
    printf("\n\nMirror of the current tree: \n");
    mirror(root); // To reorder
    print_postorder(root);

    printf("\n\nDouble Tree: \n");
    doubleTree(root);
    printf("Number of nodes = %d\n",size(root));
    printf("Root to Leaf Paths in Double Tree: \n");
    path[size(root)];
    print_paths(root, path, 0);
    return 0;
}
