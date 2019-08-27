/*
* @Author: ShenZheng
* @Date:   2019-06-18 17:16:53
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-20 16:58:22
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)
            return vector<int>();
        vector<int> result;
        stack<TreeNode*> sta;
        while(root!=NULL || !sta.empty())
        {
            if(root!=NULL)
            {
                sta.push(root);
                root=root->left;
            }
            else
            {
                root=sta.top();
                sta.pop();
                result.push_back(root->val);
                root=root->right;
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)
            return vector<int>();
        vector<int> result;
        stack<TreeNode*> sta;
        TreeNode* cur=root;
        while(cur!=NULL || !sta.empty())
        {
            if(cur!=NULL)
            {
                sta.push(cur);
                cur=cur->left;
            }
            else
            {
                cur=sta.top();
                sta.pop();
                result.push_back(cur->val);
                cur=cur->right;
            }
        }
        return result;
    }
};

int main(){

    return 0;
}