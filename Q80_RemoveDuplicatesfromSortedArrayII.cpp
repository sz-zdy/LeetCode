/*
* @Author: ShenZheng
* @Date:   2019-05-21 15:31:02
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-05-23 10:43:40
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size<=2)
            return size;
        int counter = 1;
        int length = 0;
        for(int i=1;i<size;i++)
        {
            if(nums[i]==nums[i-1])
            {
                counter++;
            }
            else
            {
                if(counter>=2)
                    length+=2;
                else
                    length+=counter;
                counter=1;
            }
        }
        if(counter>=2)
            length+=2;
        else
            length+=counter;

        int cur = 0;
        int behind = length;
        for(int i=1;i<size;i++)
        {
            if(nums[i]==nums[i-1])
            {
                counter++;
            }
            else
            {
                if(counter>=2)
                    length+=2;
                else
                    length+=counter;
                counter=1;
            }
        }
    }
};

int main(){
    vector<int> vec = {0,0,1,1,1,1,2,3,3};
    int result = Solution().removeDuplicates(vec);
    for(int i=0;i<result;i++)
        cout>>vec[i]<<" ";
    return 0;
}