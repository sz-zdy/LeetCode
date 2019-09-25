/*
* @Author: ShenZheng
* @Date:   2019-05-19 10:24:08
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-09-25 16:59:20
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
            return n;
        int minusone = 2;
        int minustwo = 1;
        int result = 0;
        for(int i=3;i<=n;i++)
        {
            result = minusone + minustwo;
            minustwo = minusone;
            minusone = result;
        }
        return result;
    }
};

int main(){
    int stairs = 3;
    int result = Solution().climbStairs(stairs);
    cout<<result<<endl;
    return 0;
}