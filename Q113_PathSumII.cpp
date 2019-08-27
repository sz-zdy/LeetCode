/*
* @Author: ShenZheng
* @Date:   2019-06-24 16:30:04
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-24 16:45:28
*/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return vector<vector<int>>();
        vector<int> tmp;
        int tmpsum=0;
        vector<vector<int>> result;
        helper(root,result,tmp,tmpsum,sum);
        return result;
    }
    void helper(TreeNode* node, vector<vector<int>>& result, vector<int>& tmp, int tmpsum, int sum)
    {
        tmpsum+=node->val;
        tmp.push_back(node->val);
        if(node->left==NULL && node->right==NULL)
        {
            if(tmpsum==sum)
                result.push_back(tmp);
        }
        if(node->left!=NULL)
            helper(node->left,result,tmp,tmpsum,sum);
        if(node->right!=NULL)
            helper(node->right,result,tmp,tmpsum,sum);
        tmp.pop_back();
    }
};

int main(){

    return 0;
}