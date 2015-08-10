//
//  main.c
//  LeetCode_MinimumDepthOfBinaryTree
//
//  Created by mac on 8/10/15.
//  Copyright © 2015 mac. All rights reserved.
//

#include <stdio.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void trans(struct TreeNode *root);
int min(const int lmin, const int rmin);
int main(int argc, const char * argv[])
{
    return 0;
}
int min(const int lmin, const int rmin)
{
    return lmin < rmin ? lmin : rmin;
}
int minDepth(struct TreeNode* root) {
    if(root == NULL) return 0;
    int lmin = minDepth(root->left);
    int rmin = minDepth(root->right);
    if(lmin==0 && rmin == 0)
        return 1;
    if(lmin == 0)
        lmin = 100000;
    if(rmin == 0)
        rmin = 100000;
    return min(lmin, rmin)+1;
    
}
