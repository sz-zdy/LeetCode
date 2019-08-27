/*
* @Author: ShenZheng
* @Date:   2019-06-25 11:10:12
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-25 11:21:11
*/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1,1);
        for(int i=2;i<=rowIndex;i++)
        {
            for(int j=i-1;j>=1;j--)
            {
                result[j]+=result[j-1];
            }
        }
        return result;
    }
};

int main(){

    return 0;
}