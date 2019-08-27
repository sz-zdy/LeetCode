/*
* @Author: ShenZheng
* @Date:   2019-04-06 10:06:49
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-04-06 10:34:20
*/

#include <iostream>
#include <vector>
using namespace std;

//**************我的解法******************
/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxV=0;
        int curV=0;
        int minH=0;
        for(unsigned int i=0;i<height.size();i++)
        {
            for(unsigned int j=i+1;j<height.size();j++)
            {
                minH=min(height[i],height[j]);
                curV=(j-i)*minH;
                maxV=max(maxV,curV);
            }
        }
        return maxV;
    }
};
*/

//好的解法：
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int maxV=0;
        while(i<j)
        {
            int h = min(height[i],height[j]);
            int curV=(j-i)*h;
            maxV=max(maxV,curV);
            while(height[i]<=h && i<j) i++;
            while(height[j]<=h && i<j) j--;
        }
        return maxV;
    }
};

int main(){
    vector<int> height={1,8,6,2,5,4,8,3,7};
    int result = Solution().maxArea(height);
    cout<<result<<endl;
    return 0;
}