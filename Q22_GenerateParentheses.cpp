/*
* @Author: ShenZheng
* @Date:   2019-04-05 15:31:13
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-04-05 16:00:37
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        Core("",0,0,n,result);
        return result;
    }

    void Core(string tmp,int LeftNum, int RightNum, int n, vector<string>& result)
    {
        if(RightNum==n)
        {
            result.push_back(tmp);
            return ;
        }
        if(LeftNum==n)
        {
            Core(tmp+")",LeftNum,RightNum+1,n,result);
        }
        else
        {
            if(LeftNum==RightNum)
            {
                Core(tmp+"(",LeftNum+1,RightNum,n,result);
            }
            else if(LeftNum>RightNum)
            {
                Core(tmp+"(",LeftNum+1,RightNum,n,result);
                Core(tmp+")",LeftNum,RightNum+1,n,result);
            }
        }
    }
};

int main(){
    int n=3;
    vector<string> result = Solution().generateParenthesis(n);
    for(auto item:result)
        cout<<item<<endl;
    return 0;
}