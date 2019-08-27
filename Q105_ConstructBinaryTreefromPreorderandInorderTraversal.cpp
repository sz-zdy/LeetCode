/*
* @Author: ShenZheng
* @Date:   2019-06-23 16:10:26
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-24 10:46:57
*/

#include <iostream>

using namespace std;
//版本一：因为形参是引用而不能使用的版本
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty())
            return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        auto it1 = find(inorder.begin(),inorder.end(),preorder[0]);
        size_t numberofleftson = it1-inorder.begin();
        root->left = buildTree(vector<int>(preorder.begin()+1,preorder.begin()+1+numberofleftson),vector<int>(inorder.begin(),it1));
        root->right = buildTree(vector<int>(preorder.begin()+1+numberofleftson,preorder.end()),vector<int>(it1,inorder.end()));
        return root;
    }
};

//版本二：能在leetcode上运行，但是效率不高的版本
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder) {
        if(preorder.empty())
            return NULL;
        return helper(preorder,inorder);
    }
    TreeNode* helper(vector<int> preorder, vector<int> inorder)
    {
        if(preorder.empty())
            return NULL;
        int rootval = preorder[0];
        TreeNode* root = new TreeNode(rootval);
        auto vinRootIterator = find(inorder.begin(),inorder.end(),rootval);
        int numberofleftson = vinRootIterator - inorder.begin();
        root->left = helper(vector<int>(preorder.begin()+1,preorder.begin()+1+numberofleftson),vector<int>(inorder.begin(),vinRootIterator));
        root->right = helper(vector<int>(preorder.begin()+1+numberofleftson,preorder.end()),vector<int>(vinRootIterator+1,inorder.end()));
        return root;
    }
};

//版本三：
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() && inorder.empty())
            return NULL;
        return helper(preorder,0,preorder.size(),inorder,0,inorder.size());
    }

    TreeNode* helper(vector<int>& preorder, int prei, int prej, vector<int>& inorder, int ini, int inj)
    {
        if(prei==prej)
            return NULL;
        TreeNode* root = new TreeNode(preorder[prei]);
        auto vinRootIterator = find(inorder.begin()+ini,inorder.begin()+inj,preorder[prei]);
        int numberofleftson = vinRootIterator-(inorder.begin()+ini);
        root->left = helper(preorder,prei+1,prei+1+numberofleftson,inorder,ini,ini+numberofleftson);
        root->right = helper(preorder,prei+1+numberofleftson,prej,inorder,ini+numberofleftson+1,inj);
    }
};

