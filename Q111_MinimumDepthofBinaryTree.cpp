/*
* @Author: ShenZheng
* @Date:   2019-06-24 15:46:42
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-24 16:10:12
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int LeftDepth = minDepth(root->left);
        int RightDepth = minDepth(root->right);
        if(LeftDepth==0 || RightDepth==0)
            return ((LeftDepth>RightDepth?LeftDepth:RightDepth)+1);
        else
            return ((LeftDepth<RightDepth?LeftDepth:RightDepth)+1);
    }
};

int main(){

    return 0;
}