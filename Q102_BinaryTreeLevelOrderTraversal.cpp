/*
* @Author: ShenZheng
* @Date:   2019-06-23 10:38:24
* @Last Modified by:   anchen
* @Last Modified time: 2019-09-15 12:08:26
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

//复习
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            rerturn result;
        queue<TreeNode*> que;
        que.push(root);
        int count = 1;
        int NumInLevel = count;

        TreeNode* tmpNode;
        vector<int> tmpVec;
        while(!que.empty()){
            tmpNode = que.front();
            tmpVec.push_back(que.tmpNode->val);

            if(tmpNode->left != NULL){
                que.push(tmpNode->left);
                count++;
            }
            if(tmpNode->right != NULL){
                que.push(tmpNode->right);
                count++;
            }

            que.pop();
            NumInLevel--;
            if(NumInLevel == 0){
                result.push_back(tmpVec);
                tmpVec.clear();
            }
        }
        return result;
    }
};

int main(){

    return 0;
}