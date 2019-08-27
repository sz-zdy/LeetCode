/*
* @Author: ShenZheng
* @Date:   2019-04-09 16:26:36
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-04-09 16:34:39
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=nums[0];
        int tmpSum=0;
        for(unsigned i=0;i<nums.size();i++)
        {
            tmpSum+=nums[i];
            maxSum=max(tmpSum,maxSum);
            if(tmpSum<0)
            {
                tmpSum=0;
            }
        }
        return maxSum;
    }
};

int main(){
    vector<int> vec={-2,-3,-1,-5};
    int result = Solution().maxSubArray(vec);
    cout<<result<<endl;
    return 0;
}