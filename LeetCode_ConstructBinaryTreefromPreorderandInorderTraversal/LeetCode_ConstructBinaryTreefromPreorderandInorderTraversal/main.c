//
//  main.c
//  LeetCode_ConstructBinaryTreefromPreorderandInorderTraversal
//
//  Created by mac on 8/5/15.
//  Copyright © 2015 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    struct TreeNode *p = malloc(sizeof(struct TreeNode));
    if (preorderSize == 0) {
        //空节点
        return NULL;
    } else {
        int rootNum = preorder[0];
        p->val = rootNum;
        int i = 0;
        while (inorder[i++] != rootNum);
        int rightTreeSize = inorderSize - i;
        int leftTreeSize = i - 1;
        p->left = buildTree(preorder + 1, leftTreeSize, inorder, leftTreeSize);
        p->right = buildTree(preorder + 1 + leftTreeSize, rightTreeSize, inorder + i, rightTreeSize);
    }
    return p;
}
void preOrder(struct TreeNode *head)
{
    if (head == NULL) {
        return;
    }
    printf("%d ", head->val);
    preOrder(head->left);
    preOrder(head->right);
}

void inOrder(struct TreeNode *head)
{
    
    if (head == NULL) {
        return;
    }
    inOrder(head->left);
    printf("%d ", head->val);
    inOrder(head->right);
}
int pre[10] = {1,2,4,5,6,7,3,8,9,10};
int in[10] = {4,5,2,6,7,1,3,9,8,10};
int main(int argc, const char * argv[]) {
    
    struct TreeNode *head =  buildTree(pre, 10, in, 10);
    preOrder(head);
    printf("\n");
    inOrder(head);
    printf("\n");
    return 0;
}
