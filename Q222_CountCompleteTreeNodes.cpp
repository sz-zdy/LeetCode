/*
 * @Description: Count Complete Tree Nodes
 * @Autor: shenzheng
 * @email: sznust@163.com
 * @Date: 2019-08-21 22:35:21
 * @LastEditors: shenzheng
 * @LastEditTime: 2019-08-22 00:15:13
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

//Solution1:最笨的办法，层遍历，这样思考的时间最少
//leetcode跑分：
// Runtime: 36 ms, faster than 46.70% of C++ online submissions for Count Complete Tree Nodes.
// Memory Usage: 29.2 MB, less than 11.11% of C++ online submissions for Count Complete Tree Nodes.
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int nodeCount = 0;    
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            root = que.front();
            que.pop();
            nodeCount++;
            if(root->left != nullptr){
                que.push(root->left);
            }
            if(root->right != nullptr){
                que.push(root->right);
            }
        }
        return nodeCount; 
    }
};


//Solution2：
//思路：完全二叉树的子树也是完全二叉树，递归实现
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int LNum = 0, RNum = 0;
        TreeNode* lNode =  root -> left;
        TreeNode* rNode =  root -> right; 
        while(lNode){ LNum ++; lNode = lNode->left;}   
        while(rNode){ RNum ++; rNode = rNode->right;} 
        if( LNum == RNum){
            return ((1<<(LNum+1))-1);
        }   
        return (1 + countNodes(root->left) + countNodes(root->right));
    }
};