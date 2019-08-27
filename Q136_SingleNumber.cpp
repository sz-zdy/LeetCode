/*
* @Author: ShenZheng
* @Date:   2019-06-26 16:47:22
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-26 16:48:36
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i=0;i<nums.size();i++)
            result=result^nums[i];
        return result;
    }
};

int main(){

    return 0;
}