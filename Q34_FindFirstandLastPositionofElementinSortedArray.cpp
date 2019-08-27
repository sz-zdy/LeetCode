/*
* @Author: ShenZheng
* @Date:   2019-04-08 21:05:28
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-04-09 14:12:44
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result={-1,-1};
        if(nums.size()<2)
            return result;
        unsigned i=0,j=nums.size()-1;
        unsigned mid;

        while(i<j)
        {
            mid=(i+j)/2;
            if(nums[mid]<target){
                i=i+1;
            }
            else if(nums[mid]>target){
                j=j-1;
            }
            else{
                break;
            }
        }
        cout<<mid<<nums[mid]<<endl;
        unsigned mid2=mid;
        if(nums[mid]==target)
        {
            i=0;j=mid2;
            while(i<j){
                mid=(i+j)/2;
                if(nums[mid]==target)
                    j=mid;
                else
                    i=mid+1;
            }
            result[0]=j;
            i=mid2;j=nums.size()-1;
            while(i<j){
                mid=(i+j)/2;
                if(nums[mid]==target)
                    i=mid+1;
                else
                    j=mid;
            }
            result[1]=i;
        }
        return result;
    }
};

int main(){
    vector<int> vec={2,2};
    int target = 0;
    vector<int> result = Solution().searchRange(vec,target);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}