//
//  main.c
//  LeetCode_PopulatingNextRightPointerInEachNode_2
//
//  Created by mac on 7/24/15.
//  Copyright (c) 2015 mac. All rights reserved.
//

#include <stdio.h>
typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *next;
}TreeNode, *lpTreeNode;
void conne(lpTreeNode root);

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode e = {6,  NULL, NULL, NULL};
    TreeNode d = {5, NULL, NULL, NULL};
    TreeNode c = {4, NULL, NULL, NULL};
    TreeNode b = {3,  &d, NULL, NULL};
    TreeNode a = {2,  &c, NULL, NULL};
    TreeNode root = {1, &a, &b, NULL};
    
    conne(&root);
    
    
    return 0;
}
static lpTreeNode tempRoot = NULL;
void conne(lpTreeNode root) {
    if (root == NULL) {
        return;
    }
    if (NULL == tempRoot) {
        root->next = NULL;
    } else {
        if (tempRoot->right != root && tempRoot->right != NULL) {//left node
            root->next = tempRoot->right;
        } else if (tempRoot->right != root && tempRoot->right == NULL){
            if (tempRoot->next == NULL) {
                root->next = NULL;
            } else if (tempRoot->next != NULL && tempRoot->next->left != NULL) {
                root->next = tempRoot->left;
            } else if (tempRoot->next != NULL && tempRoot->next->left == NULL) {
                if (tempRoot->next->right != NULL) {
                    root->next = tempRoot->next->right;
                } else {
                    root->next = NULL;
                }
            }
        } else if (tempRoot->right == root) {
            if (tempRoot->next == NULL) {
                root->next = NULL;
            } else {
                if (tempRoot->next->left != NULL) {
                    root->next = tempRoot->next->left;
                } else {
                    if (tempRoot->next->right != NULL) {
                        root->next = tempRoot->next->right;
                    } else {
                        root->next = NULL;
                    }
                }
            }
        }
    }
        tempRoot = root;
        conne(root->left);
        tempRoot = root;
        conne(root->right);
}