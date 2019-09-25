/*
* @Author: ShenZheng
* @Date:   2019-06-24 15:46:42
* @Last Modified by:   anchen
* @Last Modified time: 2019-09-15 11:38:13
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

//复习
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int LeftDepth = minDepth(root->left);
        int RightDepth = minDepth(root->right);
        if(LeftDepth==0 || RightDepth==0){
            return (LeftDepth > RightDepth ? LeftDepth : RightDepth) + 1;
        }else{
            return (LeftDepth < RightDepth ? LeftDepth : RightDepth) + 1;
        }

        return 0;
    }
};

int main(){

    return 0;
}