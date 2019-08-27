/*
* @Author: ShenZheng
* @Date:   2019-04-05 10:18:43
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-04-05 10:35:38
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())
            return vector<vector<int>>();
        vector<vector<int>> result;
        Core(nums,result,vector<int>(),0);
        return result;
    }
    void Core(vector<int>& nums,vector<vector<int>>& result, vector<int> tmp, unsigned index)
    {
        if(index==nums.size()-1)
        {
            tmp.push_back(nums[index]);
            result.push_back(tmp);
            return ;
        }
        for(unsigned i = index; i<nums.size(); i++)
        {
            swap(nums,index,i);
            tmp.push_back(nums[index]);
            Core(nums,result,tmp,index+1);
            tmp.pop_back(nums[index]);
            swap(nums,index,i);
        }
    }
    void swap(vector<int>& nums,unsigned i,unsigned j)
    {
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
};

int main(){

    return 0;
}