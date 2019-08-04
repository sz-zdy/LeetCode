/*
 * @Description: 
 * @Autor: shenzheng
 * @email: sznust@163.com
 * @Date: 2019-08-04 15:13:08
 * @LastEditors: shenzheng
 * @LastEditTime: 2019-08-04 15:30:14
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <queck>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int counter = 1;
        if(root==nullptr)
            return result;
        que.push(root);
        while(!que.empty()){
            root = que.front();
            que.pop();counter--;
            if(root->left!=nullptr) que.push(root->left);
            if(root->right!=nullptr) que.push(root->right);
            if(counter == 0){
                result.push_back(root->val);
                counter = que.size();
            }
        }
        return result;
    }
private:
    queue<TreeNode*> que;
};