/*
* @Author: ShenZheng
* @Date:   2019-06-25 09:16:09
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-25 09:16:31
*/

#include <iostream>

using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows<=0)
            return vector<vector<int>>();
        vector<int> tmp1={1};
        vector<vector<int>> result;
        result.push_back(tmp1);
        if(numRows==1)
            return result;

        tmp1.push_back(1);
        result.push_back(tmp1);
        if(numRows==2)
            return result;

        for(int i=3;i<=numRows;i++)
        {
            vector<int> tmp2(i,0);
            tmp2[0]=1;
            tmp2[i-1]=1;
            for(int j=1;j<=i-2;j++)
            {
                tmp2[j]=tmp1[j-1]+tmp1[j];
            }
            result.push_back(tmp2);
            tmp1=tmp2;
        }
        return result;
    }
};

int main(){

    return 0;
}