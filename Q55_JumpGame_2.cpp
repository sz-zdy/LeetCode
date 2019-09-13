#include <vector>
#include <iostream>

using namespace std;

//贪心策略
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int farest = 0;
        int i;
        for(i = 0; i < size; i++){
            if(farest < i){
                return false;
            }
            farest = max(farest,i+nums[i]);
        }
        return i==size;
    }
};

int main(){
    vector<int> nums = {2,3,1,1,4};
    bool result = Solution().canJump(nums);
    cout<<result<<endl;
}