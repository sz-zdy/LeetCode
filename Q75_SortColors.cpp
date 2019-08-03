/*
* @Author: ShenZheng
* @Date:   2019-05-20 23:04:28
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-05-20 23:20:47
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        if(size==0)
            return ;
        int i = -1;
        int j = size;
        int k = 0;
        while(k<j)
            if(nums[k]==0)
            {
                swap(nums[i++],nums[k]);
            }
            else if(nums[k]==2)
            {
                swap(nums[k],nums[j--]);
            }
            else
                k++;
        }
    }
};

int main(){
    vector<int> nums={0,2,1,0,2,0,0,1,2,0};
    Solution().sortColors(nums);
    for(auto item:nums)
        cout<<item<<" ";
    return 0;
}