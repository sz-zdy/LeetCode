/*
* @Author: ShenZheng
* @Date:   2019-06-23 09:42:52
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-23 10:34:13
*/

#include <iostream>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
        if(p!=NULL && q!=NULL)
            return ((p->val)==(q->val))&&(isSameTree(p->left,q->left))&&isSameTree(p->right,q->right);
        return false;
    }
};

int main(){

    return 0;
}