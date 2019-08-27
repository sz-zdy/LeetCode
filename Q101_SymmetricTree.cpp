/*
* @Author: ShenZheng
* @Date:   2019-06-23 09:52:55
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-23 10:32:46
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        if(root->left==NULL && root->right==NULL)
            return true;
        if(root->left!=NULL && root->right!=NULL)
            return helper(root->left,root->right);
        return false;
    }
    bool helper(TreeNode* left,TreeNode* right)
    {
        if(left==NULL && right==NULL)
            return true;
        if(left!=NULL && right!=NULL)
            return ((left->val==right->val) && helper(left->left,right->right) && helper(right->left,left->right));
        return false;
    }
};

int main(){

    return 0;
}