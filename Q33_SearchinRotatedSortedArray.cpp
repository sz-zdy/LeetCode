/*
* @Author: ShenZheng
* @Date:   2019-04-08 19:36:53
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-04-08 20:50:29
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        unsigned beg=0,end=nums.size()-1;
        unsigned i=0,j=end;
        unsigned mid;
        int result=-1;

        //step1：找到最小的交接位置，起始位置大于最后一个位置，则是旋转过的
        if(nums[beg]>nums[end])
        {
            while(beg<end)
            {
                mid=(beg+end)/2;
                if(nums[mid]>nums[end]) beg=mid+1;
                else end=mid;
            }
            if(target>nums[0]){
                i=0;j=end-1;
            }
            else if(target<nums[0]){
                i=end;j=nums.size()-1;
            }
            else
                return 0;
        }

        while(i<=j)
        {
            mid=(i+j)/2;
            if(nums[mid]>target)
                j=mid-1;
            else if(nums[mid]<target)
                i=mid+1;
            else
            {
                result=mid;
                break;
            }
        }
        return result;
    }
};

int main(){
    vector<int> vec={2,3,4,5,1};
    int target = 3;
    int result = Solution().search(vec,target);
    cout<<result<<endl;
    return 0;
}