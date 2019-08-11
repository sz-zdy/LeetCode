/*
 * @Description: 
 * @Autor: shenzheng
 * @email: sznust@163.com
 * @Date: 2019-08-11 09:46:08
 * @LastEditors: shenzheng
 * @LastEditTime: 2019-08-11 10:01:57
 */
#include <unordered_map>
using namespace std;

//Method1 : Time Limit Exceeded
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; ((j-i)<=k) && j<nums.size(); j++){
                if(nums[i]==nums[j])
                    return true;
            }
        }
        return false;
    }
};

//Method2:
// Runtime: 28 ms, faster than 87.59% of C++ online submissions for Contains Duplicate II.
// Memory Usage: 15.4 MB, less than 76.47% of C++ online submissions for Contains Duplicate II.
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> myMap;
        for(int i = 0; i < nums.size(); i++){
            auto ite = myMap.find(nums[i]);
            if(ite!=myMap.end() && (i-(myMap[nums[i]])<=k)){
                return true;
            }else{
                myMap[nums[i]] = i;
            } 
        }
        return false;
    }
};