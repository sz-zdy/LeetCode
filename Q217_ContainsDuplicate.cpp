/*
 * @Description: 
 * @Autor: shenzheng
 * @email: sznust@163.com
 * @Date: 2019-08-11 09:39:36
 * @LastEditors: shenzheng
 * @LastEditTime: 2019-08-11 09:39:51
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>::iterator ite = unique(nums.begin(),nums.end());
        return (ite != nums.end());
    }
};