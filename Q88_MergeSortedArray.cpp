/*
* @Author: ShenZheng
* @Date:   2019-06-15 15:52:25
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-15 16:06:53
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m+n-1;
        int j=m-1;
        int k=n-1;
        while(j>=0 || k>=0)
        {
            if(j<0)
            {
                while(k>=0)
                    nums1[i--]=nums2[k--];
            }
            if(k<0)
            {
                return ;
            }
            if(nums1[j]>=nums2[k])
                nums1[i--]=nums1[j--];
            else
                nums1[i--]=nums2[k--];
        }
    }
};

int main(){
    vector<int> nums1={1,2,3,0,0,0};
    int m=3;
    vector<int> nums2={2,5,6};
    int n=3;
    Solution().merge(nums1,m,nums2,n);
    for(auto item:nums1)
        cout<<item<<" ";
    return 0;
}