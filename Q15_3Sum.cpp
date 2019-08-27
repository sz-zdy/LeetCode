/*
* @Author: ShenZheng
* @Date:   2019-04-06 10:35:02
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-04-06 14:33:57
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//第一次尝试：没有成功，没有全部AC
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
            return vector<vector<int>>();
        unsigned i=0,j=nums.size()-1;
        int expectNum=0;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        while(i<j)
        {
            expectNum=0-nums[i]-nums[j];
        //中间的数，二分查找
            unsigned begin=i+1,end=j-1;
            unsigned mid;
            while(begin<=end)
            {
                mid=(begin+end)/2;
                if(nums[mid]==expectNum)
                {
                    vector<int> tmp={nums[i],nums[mid],nums[j]};
                    if(result.empty() || tmp!=result.back())
                        result.push_back(tmp);
                    break;
                }
                else if(nums[mid]<expectNum) begin=mid+1;
                else end=mid-1;
            }
            //根据mid和那边靠的近来调节
            if(mid-i<j-mid)
            {
                j--;
            }
            else if(mid-i>j-mid)
            {
                i++;
            }
            else
            {
                j--;i++;
            }
        }
        return result;
    }
};
*/
//第二次尝试
//可以拆分为先固定一个数，然后剩下的部分变成了两个数的和是某一个数的问题
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
            return vector<vector<int>>();
        int expectSum=0;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(unsigned i=0;i<nums.size()-2;i++)
        {
            expectSum=0-nums[i];
            unsigned j=i+1,k=nums.size()-1;
            while(j<k)
            {
                if((nums[j]+nums[k])==expectSum){
                    result.push_back(vector<int>{nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(j<k && nums[k]==nums[k-1]) k--;
                    j++;k--;
                }
                else if((nums[j]+nums[k])>expectSum){
                    k--;
                }
                else{
                    j++;
                }

            }
            while(i+1<nums.size()-2 && nums[i]==nums[i+1]) i++;
        }
        return result;
    }
};

int main(){
    vector<int> vec={-2,0,1,1,2};
    vector<vector<int>> result = Solution().threeSum(vec);
    for(auto item:result)
    {
        for(auto item2:item)
        {
            cout<<item2<<" ";
        }
        cout<<endl;
    }
    return 0;
}