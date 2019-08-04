/*
 * @Description: 
 * @Autor: shenzheng
 * @email: sznust@163.com
 * @Date: 2019-08-04 16:11:20
 * @LastEditors: shenzheng
 * @LastEditTime: 2019-08-04 16:58:12
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int counter = 0;
        while(m!=n){
            m = m>>1;
            n = n>>1;
            counter++;            
        }
        return (m<<counter);
            
    }
};

int main()
{
    int m = 8; int n = 10;
    int result = Solution().rangeBitwiseAnd(m,n);
    cout<<result<<endl;
    return 0;
}