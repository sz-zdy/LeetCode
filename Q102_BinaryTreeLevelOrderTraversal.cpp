/*
* @Author: ShenZheng
* @Date:   2019-06-23 10:38:24
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-23 15:59:43
*/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        que.push(root);
        int counter = 0;
        int number = 1;
        vector<int> tmp;
        while(!que.empty())
        {
            root=que.front();
            que.pop();
            counter++;
            if(counter>number)
            {
                counter=1;
                number=tmp.size()*2;
                result.push_back(tmp);
                tmp.clear();
            }
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

int main(){

    return 0;
}