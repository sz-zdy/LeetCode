/*
* @Author: ShenZheng
* @Date:   2019-09-10 10:01:01
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-09-10 11:19:37
*/

#include <iostream>
#include <vector>
using namespace std;

enum state{
    StateDown = -1,
    StateBegin = 0,
    StateUp = 1
};

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();

        int result = 1;

        state flag = StateBegin;
        for(int i = 1; i < nums.size(); i++){
            switch(flag){
                case StateBegin:
                    if(nums[i] > nums[i-1]){
                        result++;
                        flag = StateUp;
                    }else if(nums[i] < nums[i-1]){
                        result++;
                        flag = StateDown;
                    }
                    break;
                case StateUp:
                    if(nums[i] < nums[i-1]){
                        result++;
                        flag = StateDown;
                    }
                    break;
                case StateDown:
                    if(nums[i] > nums[i-1]){
                        result++;
                        flag = StateUp;
                    }
                    break;
            }
        }
        return result;
    }
};

int main(){
    vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    int result = Solution().wiggleMaxLength(nums);
    cout<<result<<endl;
    return 0;
}