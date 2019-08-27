/*
* @Author: ShenZheng
* @Date:   2019-05-20 14:15:52
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-05-20 16:56:29
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rowflag(m,1);
        vector<int> colflag(n,1);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    rowflag[i]=0;
                    colflag[j]=0;
                }
            }
        }
        setRowandColZeros(matrix,rowflag,colflag);
    }
    void setRowandColZeros(vector<vector<int>>& matrix,vector<int>& rowflag,vector<int>& colflag)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int k=0;k<m;k++)
        {
            if(rowflag[k]==0)
            {
                for(int j=0;j<n;j++)
                    matrix[k][j]=0;
            }
        }

        for(int k=0;k<n;k++)
        {
            if(colflag[k]==0)
            {
                for(int j=0;j<m;j++)
                    matrix[j][k]=0;
            }
        }
    }
};

int main(){
    vector<vector<int>> matrix={
      {0,1,2,0},
      {3,4,5,2},
      {1,3,1,5}
    };
    for(auto item1:matrix)
    {
        for(auto item2:item1)
            cout<<item2<<" ";
        cout<<endl;
    }
    Solution().setZeroes(matrix);
    for(auto item1:matrix)
    {
        for(auto item2:item1)
            cout<<item2<<" ";
        cout<<endl;
    }
    return 0;
}