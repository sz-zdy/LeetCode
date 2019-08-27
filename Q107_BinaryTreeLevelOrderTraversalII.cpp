/*
* @Author: ShenZheng
* @Date:   2019-06-24 10:58:11
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-24 11:13:13
*/

#include <iostream>

using namespace std;

//Version1:
//Runtime: 16 ms, faster than 25.74% of C++ online submissions for Binary Tree Level Order Traversal II.
//Memory Usage: 13.8 MB, less than 85.70% of C++ online submissions for Binary Tree Level Order Traversal II.
//
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> result;
        vector<int> tmp;
        int counter = 0;
        int number = 1;
        que.push(root);
        while(!que.empty())
        {
            counter++;
            if(counter>number)
            {
                result.insert(result.begin(),tmp);
                counter=1;
                number=tmp.size()*2;
                tmp.clear();
            }
            root = que.front();
            que.pop();
            if(root!=NULL)
            {
                tmp.push_back(root->val);
                que.push(root->left);
                que.push(root->right);
            }
        }
        return result;
    }
};

//Version2:
//Runtime: 4 ms, faster than 97.23% of C++ online submissions for Binary Tree Level Order Traversal II.
//Memory Usage: 13.8 MB, less than 76.51% of C++ online submissions for Binary Tree Level Order Traversal II.
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> result;
        vector<int> tmp;
        int counter = 0;
        int number = 1;
        que.push(root);
        while(!que.empty())
        {
            counter++;
            if(counter>number)
            {
                result.push_back(tmp);
                counter=1;
                number=tmp.size()*2;
                tmp.clear();
            }
            root = que.front();
            que.pop();
            if(root!=NULL)
            {
                tmp.push_back(root->val);
                que.push(root->left);
                que.push(root->right);
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
int main(){

    return 0;
}