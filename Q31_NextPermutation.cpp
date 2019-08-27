/*
* @Author: ShenZheng
* @Date:   2019-04-06 16:24:22
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-04-08 19:09:56
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<2)
            return ;
        int n = nums.size(), k, l;
        for(k=n-2; k>=0; k--)
        {
            if(nums[k]<nums[k+1])
                break;
        }
        if(k<0)
        {
            reverse(nums.begin(),nums.end());
            return ;
        }
        else
        {
            for(l=n-1;l>k;l--)
            {
                if(nums[l]>nums[k])
                    break;
            }
            swap(nums[l],nums[k]);
            reverse(nums.begin()+k+1,nums.end());
        }
    }
};

int main(){
    vector<int> vec={2,1,3};
    Solution().nextPermutation(vec);
    for(auto item:vec) cout<<item<<" ";
    return 0;
}