/*
* @Author: ShenZheng
* @Date:   2019-06-24 11:14:47
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-24 14:42:47
*/

#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
            return NULL;
        return helper(nums,0,nums.size());
    }

    TreeNode* helper(vector<int>& nums,int i,int j)
    {
        if(i==j)
            return NULL;
        int mid = static_cast<int>((i+j)/2);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums,i,mid);
        root->right = helper(nums,mid+1,j);
        return root;
    }
};

int main(){

    return 0;
}