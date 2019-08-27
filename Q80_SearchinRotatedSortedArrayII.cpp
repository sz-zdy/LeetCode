/*
* @Author: ShenZheng
* @Date:   2019-05-23 11:22:43
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-05-28 10:28:42
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size==0)
            return false;
        int i=0;
        int j=size-1;
        int mid =(i+j)/2;
        while()
        {

        }
    }
};

int main(){
    vector<int> vec={2,5,6,0,0,1,2};
    int target = 0;
    bool result = Solution().search(vec,target);
    cout<<result<<endl;
    return 0;
}