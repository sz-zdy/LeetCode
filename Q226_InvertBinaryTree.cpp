/*
 * @Description: Invert Binary Tree
 * @Autor: shenzheng
 * @email: sznust@163.com
 * @Date: 2019-08-22 22:50:41
 * @LastEditors: shenzheng
 * @LastEditTime: 2019-08-22 23:01:28
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return root;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};