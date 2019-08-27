/*
* @Author: ShenZheng
* @Date:   2019-05-04 21:18:47
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-05-04 21:37:23
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n<0)
            return vector<vector<int>>();
        vector<vector<int>> result(n,vector<int>(n,0));
        int StartNum = 1;
        int LeftUp=0;
        int RightDw=0;
        for(int i = 0; i < (n+1)/2; i++)
        {
            LeftUp = i;
            RightDw = n-i-1;
            GenACircle(LeftUp,RightDw,StartNum,result);
        }
        return result;
    }
    void GenACircle(int LU, int RD, int& Num,vector<vector<int>>& result)
    {
        for(int i=LU; i<=RD; i++)
        {
            result[LU][i]=Num++;
        }
        for(int i=LU+1; i<=RD; i++)
        {
            result[i][RD]=Num++;
        }
        for(int i=RD-1;i>=LU;i--)
        {
            result[RD][i]=Num++;
        }
        for(int i=RD-1;i>LU;i--)
        {
            result[i][LU]=Num++;
        }
    }
};

int main(){
    int n=4;
    vector<vector<int>> result = Solution().generateMatrix(n);
    for(auto item1:result)
    {
        for(auto item2:item1)
            cout<<item2<<" ";
        cout<<endl;
    }
    return 0;
}