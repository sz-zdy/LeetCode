/*
* @Author: ShenZheng
* @Date:   2019-06-21 08:38:32
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-21 10:49:20
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> G = vector<int>(n+1,0);
        G[0]=G[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                G[i]+=G[j-1]*G[i-j];
            }
        }
        return G[n];
    }
};

int main(){
    int n = 3;
    int result = Solution().numTrees(n);
    cout<<result<<endl;
    return 0;
}