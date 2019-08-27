/*
* @Author: ShenZheng
* @Date:   2019-06-24 16:47:45
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-24 21:23:44
*/

#include <iostream>

using namespace std;

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL)
            return ;
        stack<TreeNode*> sta;
        vector<TreeNode*> vec;
        sta.push(root);
        while(!sta.empty())
        {
            root=sta.top();
            sta.pop();
            vec.push_back(root);
            if(root->right!=NULL)
                sta.push(root->right);
            if(root->left!=NULL)
                sta.push(root->left);
        }
        for(int i=0;i<vec.size()-1;i++)
        {
            vec[i]->left=NULL;
            vec[i]->right=vec[i+1];
        }
        return vec[0];
    }
};

int main(){

    return 0;
}