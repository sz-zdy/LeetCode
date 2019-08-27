/*
* @Author: ShenZheng
* @Date:   2019-06-27 14:25:55
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-29 10:30:18
*/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> sta;
        vector<int> result;
        if(root==NULL)
            return result;
        sta.push(root);
        while(!sta.empty())
        {
            root=sta.top();
            sta.pop();
            result.insert(result.begin(),root->val);
            if(root->left!=NULL)
                sta.push(root->left);
            if(root->right!=NULL)
                sta.push(root->right);
        }
        return result;
    }
};

int main(){

    return 0;
}