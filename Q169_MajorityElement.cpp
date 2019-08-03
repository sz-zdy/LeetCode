/*
* @Author: ShenZheng
* @Date:   2019-08-03 10:02:02
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-08-03 14:20:46
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

//1. My original Solution
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,unsigned> maps;
        for(int item:nums)
        {
            auto it = maps.find(item);
            if(it==maps.end())
                maps[item] = 0;
            else
                maps[item]++;
        }
        int result = maps.cbegin()->first;
        for(auto& item:maps)
        {
            if(item.second>=(maps[result]))
                result = item.first;
        }
        return result;
    }
};

//2. Most stared Solution in Leetcode
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int Major = nums[0], counter = 0;
        for(int i = 0; i < nums.size(); i++){
            if(counter == 0){
                Major = nums[i];
                counter = 1;
            }else if(Major == nums[i]){
                counter++;
            }else{
                counter--;
            }
        }
        return Major;
    }
};

//3. A very neat Solution
class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};

int main(){
    vector<int> nums = {1,2,7,1,1,2,5,5,2,1,1,1,9,1,1};  //1 1 1 1 1 1 1 1 2 2 2 5 5 9
    int result = Solution2().majorityElement(nums);
    cout<<result<<endl;
    return 0;
}