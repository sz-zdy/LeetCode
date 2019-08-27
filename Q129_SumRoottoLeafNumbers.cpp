/*
* @Author: ShenZheng
* @Date:   2019-06-26 14:27:46
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-26 14:43:39
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        long result = 0;
        long tmp = 0;
        helper(root,tmp,result);
        return result;
    }
    void helper(TreeNode* root, long tmp, long& result)
    {
        tmp=tmp*10+(root->val);
        if(root->left==NULL && root->right==NULL)
            result+=tmp;
        if(root->left!=NULL)
            helper(root->left,tmp,result);
        if(root->right!=NULL)
            helper(root->right,tmp,result);
    }
};

int main(){

    return 0;
}