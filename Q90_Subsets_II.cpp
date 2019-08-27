/*
* @Author: ShenZheng
* @Date:   2019-06-17 14:38:31
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-17 15:49:26
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty()) return vector<vector<int>>();
        vector<vector<int>> result={{}};
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();)
        {
            int count = 0;  //相同元素的个数
            while(i+count<nums.size() && nums[i+count]==nums[i]) count++;
            int previosN = result.size();
            for(int j=0;j<previosN;j++)
            {
                vector<int> tmp=result[j];
                for(int k=0;k<count;k++)
                {
                    tmp.push_back(nums[i]);
                    result.push_back(tmp);
                }
            }
            i=i+count;
        }
        return result;
    }
};

int main(){
    vector<int> nums={1,2,3,3};
    vector<vector<int>> result = Solution().subsetsWithDup(nums);
    for(auto item:result)
    {
        for(auto item2:item)
        {
            cout<<item2<<" ";
        }
        cout<<endl;
    }
    return 0;
}