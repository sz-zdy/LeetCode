/*
* @Author: ShenZheng
* @Date:   2019-04-05 13:14:37
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-04-05 15:10:55
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        recursion(nums,0,nums.size(),result);
        return result;
    }

    void recursion(vector<int> nums,int index_beg, int index_end, vector<vector<int>>& result)
    {
        if(index_beg==index_end-1)
        {
            result.push_back(nums);
            return ;
        }
        for(int i = index_beg; i<index_end; i++)
        {
            if(i!=index_beg && nums[index_beg]==nums[i])
                continue ;
            swap(nums[index_beg],nums[i]);
            recursion(nums,index_beg+1,index_end,result);
        }
    }
};

int main(){
    vector<int> vec={1,1,2,4};
    vector<vector<int>> result = Solution().permuteUnique(vec);
    for(auto item1:result)
    {
        for(auto item2:item1)
        {
            cout<<item2<<" ";
        }
        cout<<endl;
    }
    return 0;
}