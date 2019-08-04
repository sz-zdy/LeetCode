/*
 * @Description: 
 * @Autor: shenzheng
 * @email: sznust@163.com
 * @Date: 2019-08-04 10:35:00
 * @LastEditors: shenzheng
 * @LastEditTime: 2019-08-04 12:15:25
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    int rob(vector<int>& nums) {
        return rob(nums,nums.size()-1);
    }
private:
    int rob(vector<int>& nums, int index) {
        if(index<0)
            return 0;
        return max(rob(nums,index-2)+nums[index],rob(nums,index-1));
    }
};

class Solution2 {
public:
    int rob(vector<int>& nums) {
        int *aux = new int[nums.size()];
        for(int i=0;i<nums.size();i++){
            aux[i] = max( ( (i-2<0) ? 0 : aux[i-2]) + nums[i] , (i-1<0)?0:aux[i-1] );
        }
        return aux[nums.size()-1];
    }
};

class Solution3 {
public:
    int rob(vector<int>& nums) {
        int preOne = 0, preTwo = 0;
        int cur = 0;
        for(int i=0; i<nums.size(); i++){
            preTwo = preOne;
            preOne = cur;
            cur = max(preTwo + nums[i] , preOne);
        }
        return cur;
    }
};

int main()
{
    vector<int> nums = {2,7,9,3,1};
    int result =  Solution3().rob(nums);
    cout<<result<<endl;
    return 0;
}