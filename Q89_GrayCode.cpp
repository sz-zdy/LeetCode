/*
* @Author: ShenZheng
* @Date:   2019-06-15 16:08:00
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-15 19:41:59
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n<0)
            return vector<int>();
        int number=1<<n;
        int index=0;
        vector<int> result;
        while(index<number)
        {
            result.push_back(index^(index>>1));
            index++;
        }
        return result;
    }
};

int main(){
    int n=3;
    vector<int> result=Solution().grayCode(n);
    for(auto item:result)
    {
        cout<<item<<" ";
    }
    return 0;
}