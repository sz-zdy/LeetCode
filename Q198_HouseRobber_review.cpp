/*
 * @Description: 
 * @Autor: shenzheng
 * @email: sznust@163.com
 * @Date: 2019-08-23 00:12:49
 * @LastEditors: shenzheng
 * @LastEditTime: 2019-08-23 00:24:51
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int preTwo = 0;
        int preOne =0;
        int cur = 0;
        for(int i = 0; i < nums.size(); i++){
            preTwo = preOne;
            preOne = cur;
            cur = max((nums[i] + preTwo),preOne);
        }
        return cur;
    }
};