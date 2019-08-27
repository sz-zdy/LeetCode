/*
* @Author: ShenZheng
* @Date:   2019-04-09 16:41:48
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-04-09 17:27:22
*/

#include <iostream>
#include <vector>
using namespace std;

//方法1：递归实现
/*
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<=1) return true;
        int size=nums.size()-1;
        return Core(nums,0,size);
    }
    bool Core(vector<int>& nums,int index,int& size)
    {
        if(nums[index]+index>=size)
            return true;
        if(nums[index]==0)
            return false;
        for(int i=1;i<=nums[index];i++)
        {
            if(Core(nums,index+i,size))
                return true;
        }
        return false;
    }
};
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size=nums.size();
        vector<bool> record(size,false);
        record[size-1]=true;
        for(int i=size-2;i>=0;i--)
        {
            for(int j=nums[i];j>=1;j--)
            {
                if(record[i+j])
                {
                    record[i]=true;
                    break;
                }
            }
        }
        for(auto item:record) cout<<item<<" ";
        cout<<endl;
    return record[0];
    }
};

int main(){
    vector<int> vec1={2,3,1,1,4};
    vector<int> vec2={3,2,1,0,4};
    bool flag1=Solution().canJump(vec1);
    bool flag2=Solution().canJump(vec2);
    cout<<flag1<<endl;
    cout<<flag2<<endl;
    return 0;
}