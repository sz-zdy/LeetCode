/*
* @Author: ShenZheng
* @Date:   2019-06-23 11:35:47
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-23 15:58:17
*/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> sta1;
        stack<TreeNode*> sta2;
        bool flag = true;
        vector<vector<int>> result;
        vector<int> tmp;
        sta1.push(root);
        while(!sta1.empty() || !sta2.empty())
        {
            if(flag)
            {
                while(!sta1.empty())
                {
                    root=sta1.top();
                    sta1.pop();
                    if(root!=NULL)
                    {
                        tmp.push_back(root->val);
                        sta2.push(root->left);
                        sta2.push(root->right);
                    }
                }
                if(!tmp.empty())
                    result.push_back(tmp);
                tmp.clear();
                flag=!flag;
            }
            else
            {
                while(!sta2.empty())
                {
                    root=sta2.top();
                    sta2.pop();
                    if(root!=NULL)
                    {
                        tmp.push_back(root->val);
                        sta1.push(root->right);
                        sta1.push(root->left);
                    }
                }
                if(!tmp.empty())
                    result.push_back(tmp);
                tmp.clear();
                flag=!flag;
            }
        }
        return result;
    }
};

int main(){

    return 0;
}