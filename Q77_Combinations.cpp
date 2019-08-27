/*
* @Author: ShenZheng
* @Date:   2019-05-21 10:38:25
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-05-21 10:59:41
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(n<1 || k>n)
            return vector<vector<int>>();
        vector<bool> flag(n,false);
        vector<int> tmp;
        vector<vector<int>> result;
        Core(0,k,n,flag,tmp,result);
        return result;
    }

    void Core(int start,int k,int n,vector<bool>& flag, vector<int> tmp,  vector<vector<int>>& result)
    {
        if(k==0)
            result.push_back(tmp);
        else
        {
            for(int i=start;i<n;i++)
            {
                if(flag[i]==false)
                {
                    flag[i]=true;
                    tmp.push_back(i+1);
                    Core(i+1,k-1,n,flag,tmp,result);
                    tmp.pop_back();
                    flag[i]=false;
                }
            }
        }
    }
};

int main(){
    int n=4;
    int k=2;
    vector<vector<int>> result = Solution().combine(n,k);
    for(auto item1:result)
    {
        for(auto item2:item1)
            cout<<item2<<" ";
        cout<<endl;
    }

    return 0;
}