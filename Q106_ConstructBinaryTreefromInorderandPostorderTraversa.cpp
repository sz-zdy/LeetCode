/*
* @Author: ShenZheng
* @Date:   2019-06-24 10:47:41
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-24 11:30:14
*/

#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty())
            return NULL;
        return helper(inorder,0,inorder.size(),postorder,0,postorder.size());
    }
    TreeNode* helper(vector<int>& inorder,int ini,int inj, vector<int>& postorder,int posti,int postj)
    {
        if(ini>=inj)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postj-1]);
        auto iterator = find(inorder.begin()+ini,inorder.begin()+inj,postorder[postj-1]);
        int numberofleftson = iterator-(inorder.begin()+ini);
        root->left = helper(inorder,ini,ini+numberofleftson,postorder,posti,posti+numberofleftson);
        root->right = helper(inorder,ini+numberofleftson+1,inj,postorder,posti+numberofleftson,postj-1);
        return root;
    }
};

int main(){

    return 0;
}