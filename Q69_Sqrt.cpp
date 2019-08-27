/*
* @Author: ShenZheng
* @Date:   2019-05-19 10:12:21
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-05-19 10:22:43
*/

#include <iostream>

using namespace std;
/*
class Solution {
public:
    int mySqrt(int x) {
        long int i = 0;
        long lx = x;
        while(i*i<lx)
        {
            i++;
        }
        long int result;
        if(i*i==x)
            result = i;
        else
            result = i-1;
        return static_cast<int>(result);
    }
};
*/
//别人的解法
class Solution {
public:
    int mySqrt(int x) {
        int low = 0,  high = x, mid;
        if(x<2) return x; // to avoid mid = 0
        while(low<high)
        {
            mid = (low + high)/2;
            if(x/mid >= mid) low = mid+1;
            else high = mid;
        }
        return high-1;

    }
};
int main(){
    int input = 2147483647;
    int result = Solution().mySqrt(input);
    cout<<result<<endl;
    return 0;
}