/*
 * @Description: 152. Maximum Product Subarray
 * @Autor: shenzheng
 * @email: sznust@163.com
 * @Date: 2019-08-27 09:39:44
 * @LastEditors: shenzheng
 * @LastEditTime: 2019-08-27 10:18:30
 */

#include <vector>
#include <iostream>

using namespace std;

//思路：
//1.记录数组中负数的个数
//2.重新开始新的数组的依据是：当前的乘积为0或遇到的负数是最后一个负数且当前的乘积为正数
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int negNums = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]<0)
                negNums++;
        }
        cout<<"negNums:"<<negNums<<endl;
        int maxProduct = nums[0];
        int tmpProduct = 1;
        for(int i = 0; i < nums.size(); i++){
            tmpProduct *= nums[i];
            cout<<i<<" "<<tmpProduct<<" "<<maxProduct<<endl;
            if(nums[i]<0) negNums--;
            if(tmpProduct > maxProduct){
                maxProduct = tmpProduct;
            }
            if(tmpProduct == 0 || (tmpProduct < 0 && negNums == 0)){
                tmpProduct = 1;
            }
        }
        return maxProduct;
    }
};

int main()
{
    vector<int> nums = {2,-5,-2,-4,3};
    int result = Solution().maxProduct(nums);
    cout<<result<<endl;
    return 0;
}
