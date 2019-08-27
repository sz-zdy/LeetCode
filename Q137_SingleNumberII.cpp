/*
* @Author: ShenZheng
* @Date:   2019-06-27 08:55:23
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-27 09:37:15
*/

#include <iostream>

using namespace std;

//方法1：利用位之和是3的倍数
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int W = sizeof(int) * 8;
        int count[W];
        fill_n(&count[0], W, 0);
        int N = nums.size();
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < W; j++)
            {
                count[j]+=(nums[i]>>j) & 1;
                count[j]%=3;
            }
        }
        int result = 0;
        for(int i = 0; i < W; i++)
        {
            result += count[i]<<i;
        }
        return result;
    }
};

//方法2：
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        return result;
    }
};


int main(){

    return 0;
}