/*
* @Author: ShenZheng
* @Date:   2019-05-18 16:32:55
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-05-18 16:45:05
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> arr(n,0);
        arr[n-1]=grid[m-1][n-1];
        for(int j=n-2;j>=0;j--)
            arr[j]=grid[m-1][j]+arr[j+1];

        for(int i=m-2;i>=0;i--)
        {
            arr[n-1]+=grid[i][n-1];
            for(int j=n-2;j>=0;j--)
            {
                arr[j]=grid[i][j]+std::min(arr[j],arr[j+1]);
            }
        }
        return arr[0];
    }
};

int main(){
    vector<vector<int>> vec={
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    int sum = Solution().minPathSum(vec);
    cout<<sum<<endl;
    return 0;
}