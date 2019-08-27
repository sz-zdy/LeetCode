/*
* @Author: ShenZheng
* @Date:   2019-06-27 14:20:30
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-27 15:09:53
*/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int> result;
         if(root==NULL)
            return result;
         stack<TreeNode*> sta;
         sta.push(root);
         while(!sta.empty())
         {
            root=sta.top();
            sta.pop();
            result.push_back(root->val);
            if(root->right) sta.push(root->right);
            if(root->left) sta.push(root->left);
         }
         return result;
    }
};

int main(){

    return 0;
}