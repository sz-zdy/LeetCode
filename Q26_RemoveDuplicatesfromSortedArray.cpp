/*
* @Author: ShenZheng
* @Date:   2019-04-06 15:31:23
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-04-06 15:46:06
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//解法一
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        auto cur = nums.begin();
        cur++;
        while(cur!=nums.end())
        {
            if(*cur==*(cur-1))
            {
                cur=nums.erase(cur);
            }
            else
                cur++;
        }
        return nums.size();
    }
};
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        auto unique_end = unique(nums.begin(),nums.end());
        nums.erase(unique_end,nums.end());
        return nums.size();
    }
};
int main(){
    vector<int> nums ={1,1,2};
    int len = Solution().removeDuplicates(nums);
    cout<<len<<endl;
    for(auto item:nums)
        cout<<item<<" ";
    return 0;
}