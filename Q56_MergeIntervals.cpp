/*
* @Author: ShenZheng
* @Date:   2019-04-22 20:18:52
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-04-22 20:37:15
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        unsigned size = intervals.size();
        if(size<=1)
            return intervals;
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){return a[0]<b[0];});
        vector<int> prev=intervals[0];
        for(unsigned i=1;i<size;i++)
        {
            if(prev[1]>=intervals[i][0])
            {
                prev[1]=max(prev[1],intervals[i][1]);
            }
            else
            {
                result.push_back(prev);
                prev=intervals[i];
            }
        }
        result.push_back(prev);
        return result;
    }
};

int main(){
    vector<vector<int>> vec={
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };
    vector<vector<int>> result = Solution().merge(vec);
    for(auto item1:result)
    {
        for(auto item2:item1)
            cout<<item2<<" ";
        cout<<endl;
    }
    return 0;
}