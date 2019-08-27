/*
* @Author: ShenZheng
* @Date:   2019-06-22 17:09:16
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-22 17:26:59
*/

#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        bool leftbool = true;
        bool rightbool = true;
        if(root->left!=NULL)
        {
            if((root->val)>(root->left->val))
                leftbool=isValidBST(root->left);
            else
                return false;
        }
        if(root->right!=NULL)
        {
            if((root->val)<(root->right->val))
                rightbool=isValidBST(root->right);
            else
                return false;
        }
        return (leftbool && rightbool);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        vector<int> arr;
        stack<TreeNode*> sta;
        //中序遍历
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
                arr.push_back(root->val);
                root=root->right;
            }
        }

        //遍历检测是不是排序的
        int arrsize=arr.size();
        if(arrsize<=1)
            return true;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]<=arr[i-1])
                return false;
        }
        return true;
    }
};

int main(){

    return 0;
}