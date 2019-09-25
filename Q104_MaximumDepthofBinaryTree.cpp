/*
* @Author: ShenZheng
* @Date:   2019-06-23 16:00:24
* @Last Modified by:   anchen
* @Last Modified time: 2019-09-15 10:34:58
*/

#include <iostream>

using namespace std;

//Solution1
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        return std::max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

//Solution2:复习
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root != NULL)
            return max(maxDepth(root->left),maxDepth(root->right)) + 1
        return 0;
    }
};


int main(){

    return 0;
}