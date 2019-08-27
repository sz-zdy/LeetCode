/*
* @Author: ShenZheng
* @Date:   2019-05-21 11:22:40
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-05-21 11:36:33
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty())
            return vector<vector<int>>();
        vector<int> tmp;
        vector<vector<int>> result;
        int index = 0;
        Core(nums,index,nums.size(),tmp,result);
        return result;
    }
    void Core(vector<int>& nums,int index,int size,vector<int> tmp,vector<vector<int>>& result)
    {
        if(index==size)
        {
            result.push_back(tmp);
            return ;
        }
        Core(nums,index+1,size,tmp,result);
        tmp.push_back(nums[index]);
        Core(nums,index+1,size,tmp,result);
    }
};

int main(){
    vector<int> nums={1,2,3};
    vector<vector<int>> result = Solution().subsets(nums);
    for(auto item1:result)
    {
        for(auto item2:item1)
            cout<<item2<<" ";
        cout<<endl;
    }
    return 0;
}