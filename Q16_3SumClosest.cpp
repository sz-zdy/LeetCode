/*
* @Author: ShenZheng
* @Date:   2019-04-06 14:34:21
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-04-06 14:58:46
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)
            return int();
        int Sum=0;
        int minDiff=target-nums[0]-nums[1]-nums[2]; //初始先设置
        sort(nums.begin(),nums.end());
        for(unsigned i=0;i<nums.size()-2;i++)
        {
            unsigned j=i+1,k=nums.size()-1;
            while(j<k)
            {
                Sum=nums[i]+nums[j]+nums[k];
                if(Sum==target){
                    return target;
                }
                else
                {
                    int curDiff=target-Sum;
                    minDiff=abs(minDiff)<abs(curDiff)?minDiff:curDiff;
                    if(curDiff>0)
                        j++;
                    else
                        k--;
                }
            }
            while(i+1<nums.size()-2 && nums[i]==nums[i+1]) i++;
        }
        return (target-minDiff);
    }
};

int main(){
    vector<int> vec={0,0,0};
    int target = 1;
    int Sum = Solution().threeSumClosest(vec,target);
    cout<<Sum<<endl;
    return 0;
}