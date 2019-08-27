/*
* @Author: ShenZheng
* @Date:   2019-06-23 16:00:24
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-23 16:09:38
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        return std::max(maxDepth(root->left),maxDepth(root->roght))+1;
    }
};

int main(){

    return 0;
}