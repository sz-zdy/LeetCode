/*
* @Author: ShenZheng
* @Date:   2019-05-17 09:05:49
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-05-17 10:02:30
*/

#include <iostream>
#include <vector>
using namespace std;

//方法1
/*
class Solution {
public:
    int uniquePaths(int m, int n)
    {
        if(m<=0 || n<=0)
            return 0;
        return Core(m,n);
    }

    int Core(int m, int n)
    {
        if(m==1 && n==1)
            return 1;
        int result = 0;
        if(m>1) result+=Core(m-1,n);
        if(n>1) result+=Core(m,n-1);
        return result;
    }
};
*/

//方法2
/*
class Solution {
public:
    int uniquePaths(int m, int n)
    {
        if(m<=0 || n<=0)
            return 0;
        vector<vector<int>> vec(m,vector<int>(n,0));
        vec[0][0] = 1;
        for(int i = 0;i<std::min(m,n);i++)
        {
            for(int j=i+1;j<m;j++)
                vec[j][i]=vec[j-1][i]+((i-1<0)?0:vec[j][i-1]);
            for(int k=i+1;k<n;k++)
                vec[i][k]=vec[i][k-1]+((i-1<0)?0:vec[i-1][k]);
            if(i<std::min(m,n)-1)
                vec[i+1][i+1]=vec[i][i+1]+vec[i+1][i];
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                cout<<vec[i][j]<<" ";
            cout<<endl;
        }
        return vec[m-1][n-1];
    }
};
*/

class Solution {
public:
    int uniquePaths(int m, int n)
    {
        if(m<=0 || n<=0)
            return 0;
        vector<int> vec(n,1);
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                vec[j]+=vec[j-1];
            }
        }
        return vec[n-1];
    }
};

int main(){
    int m = 3, n = 4;
    int result = Solution().uniquePaths(m,n);
    cout<<result<<endl;
    return 0;
}