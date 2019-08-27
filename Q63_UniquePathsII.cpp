/*
* @Author: ShenZheng
* @Date:   2019-05-18 15:47:56
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-05-18 16:25:49
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty())
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1)
        {
            return 0;
        }
        vector<long> arr(n,1);          //int居然会出现溢出，要使用long
        for(int j=n-2;j>=0;j--)
        {
            if(obstacleGrid[m-1][j]==1 || arr[j+1]==0)
                arr[j]=0;
        }

        for(int i=m-2;i>=0;i--)
        {
            if(obstacleGrid[i][n-1]==1)
                arr[n-1]=0;
            for(int j=n-2;j>=0;j--)
            {
                if(obstacleGrid[i][j]==1)
                    arr[j]=0;
                else
                    arr[j]+=arr[j+1];
            }
        }

        return arr[0];
    }
};

int main(){
    int m=3;
    int n=3;
    vector<vector<int>> ob(m,vector<int>(n,0));
    ob[1][1]=1;
    int result = Solution().uniquePathsWithObstacles(ob);
    cout<<result<<endl;
    return 0;
}