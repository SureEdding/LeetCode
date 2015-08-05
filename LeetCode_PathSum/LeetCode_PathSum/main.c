//
//  main.c
//  LeetCode_PathSum
//
//  Created by mac on 7/23/15.
//  Copyright (c) 2015 mac. All rights reserved.
//

#include <stdio.h>

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode, *lpTreeNode;

int hasPathSum(lpTreeNode root, int sum);

int main(int argc, const char * argv[]) {

    TreeNode root = {5, NULL, NULL};
    TreeNode a = {4,  NULL, NULL};
    TreeNode b = {8,  NULL, NULL};
    TreeNode c = {11, NULL, NULL};
    TreeNode d = {13, NULL, NULL};
    TreeNode e = {4,  NULL, NULL};
    TreeNode f = {7,  NULL, NULL};
    TreeNode g = {2,  NULL, NULL};
    TreeNode h = {1,  NULL, NULL};
    root.left = &a;
    root.right = &b;
    a.left = &c;
    c.left = &f;
    c.right = &g;
    b.left = &d;
    b.right = &e;
    e.right = &h;
    char *p="hell";
    p[1]='E';
    
    int i=0;
    i=(i++);
    printf("%d\n", hasPathSum(&root, 22));
    
    return 0;
}



int hasPathSum(lpTreeNode root, int sum)
{
    if (root == NULL)
        return 0;
    int result;
    if (root->left == NULL && root->right == NULL)
    {//leaf node
        if (root->val == sum) {
            return -1;
        }
        else{
            return 0;
        }
    }
    
    result = hasPathSum(root->left, sum - root->val);
    if (result == -1) {
        return -1;
    }
    result = hasPathSum(root->right, sum - root->val);
    if (result == -1) {
        return -1;
    }
    return 0;
}





