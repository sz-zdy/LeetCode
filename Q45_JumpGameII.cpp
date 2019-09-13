/*
* @Author: ShenZheng
* @Date:   2019-04-05 15:24:59
* @Last Modified by:   anchen
* @Last Modified time: 2019-09-13 10:24:25
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0;
        int end = 0;
        int result = 0;
        while(end < nums.size()-1){
            result++;

            int temp = 0;       //本轮循环中的最远值
            for(int i = start; i <= end; i++){
                temp = max(temp,i+nums[i]);
                if(temp >= nums.size()-1)
                    break;
            }
            start = end + 1;
            end = temp;
        }
        return result;
    }
};

int main(){
    vector<int> nums={2,3,1,1,4};
    int result = Solution().jump(nums);
    cout<<result<<endl;
    return 0;
}