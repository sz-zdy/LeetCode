/*
* @Author: ShenZheng
* @Date:   2019-06-24 14:46:03
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-24 15:10:59
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        if(helper(root)<0)
            return false;
        return true;
    }
    int helper(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        else
        {
            int left = helper(root->left);
            if(left<0)
                return -1;
            int right = helper(root->right);
            if(right<0)
                return -1;
            if(abs(left-right)>1)
                return -1;
            else
                return ((left>right?left:right)+1);
        }
    }
};

int main(){

    return 0;
}