/*
* @Author: ShenZheng
* @Date:   2019-04-06 15:00:27
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-04-06 15:41:53
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4)
            return vector<vector<int>>();
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(unsigned i=0;i<nums.size()-3;i++)
        {
            for(unsigned j=i+1;j<nums.size()-2;j++)
            {
                int expectSum = target - nums[i] - nums[j];
                unsigned k=j+1,l=nums.size()-1;
                while(k<l)
                {
                    if(expectSum==(nums[k]+nums[l]))
                    {
                        result.push_back(vector<int>{nums[i],nums[j],nums[k],nums[l]});
                        while(k<l && nums[k]==nums[k+1]) k++;
                        while(k<l && nums[l]==nums[l-1]) l--;
                        k++;l--;
                    }
                    else if(expectSum>(nums[k]+nums[l]))
                        k++;
                    else
                        l--;
                }
                while(j<nums.size()-2 && nums[j]==nums[j+1]) j++;
            }
            while(i<nums.size()-3 && nums[i]==nums[i+1]) i++;
        }
        return result;
    }
};

int main(){
    vector<int> vec={1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = Solution().fourSum(vec,target);
    for(auto item:result)
    {
        for(auto item2:item)
            cout<<item2<<" ";
        cout<<endl;
    }
    return 0;
}