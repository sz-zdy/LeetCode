/*
* @Author: ShenZheng
* @Date:   2019-06-24 16:12:00
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-24 16:29:46
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return false;
        return helper(root,0,sum);
    }
    bool helper(TreeNode* node,int tmp,int sum)
    {
        tmp+=node->val;
        if(node->left==NULL && node->right==NULL)
            return tmp==sum;
        bool leftresult = false;
        bool rightresult = false;
        if(node->left!=NULL)
            leftresult = helper(node->left,tmp,sum);
        if(node->right!=NULL)
            rightresult = helper(node->right,tmp,sum);
        return (leftresult||rightresult);
    }
};

int main(){

    return 0;
}