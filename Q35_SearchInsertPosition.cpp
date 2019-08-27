/*
* @Author: ShenZheng
* @Date:   2019-04-09 14:11:53
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-04-09 14:23:49
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        int beg=0,end=nums.size()-1;
        int mid;
        int result=-1;
        while(beg<=end)
        {
            mid=(beg+end)/2;
            if(nums[mid]>target)
                end=mid-1;
            else if(nums[mid]<target)
                beg=mid+1;
            else
            {
                result=mid;break;
            }
        }
        if(result<0) result=beg;
        return result;
    }
};

int main(){
    vector<int> vec={1,3,5,6};
    int target =7;
    int result = Solution().searchInsert(vec,target);
    cout<<result<<endl;
    return 0;
}