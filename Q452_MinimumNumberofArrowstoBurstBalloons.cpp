/*
* @Author: anchen
* @Date:   2019-09-13 10:41:08
* @Last Modified by:   anchen
* @Last Modified time: 2019-09-13 11:33:26
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;

        sort(points.begin(),points.end(),[](const vector<int>& vec1,const vector<int>& vec2)->bool{ return vec1[0] < vec2[0];});

        int curStart = points[0][0];
        int curEnd = points[0][1];
        int result = 1;

        for(int i = 1; i < points.size(); i++){
            if(points[i][0]>=curStart && points[i][0] <= curEnd){
                curStart = points[i][0];
                curEnd = min(curEnd,points[i][1]);
            }else{
                curStart = points[i][0];
                curEnd = points[i][1];
                result++;
            }
        }
        return result;
    }
};

int main(){
    vector<vector<int>> points={{10,16},{2,8},{1,6},{7,12}};
    int result = Solution().findMinArrowShots(points);
    cout<<result<<endl;
    return 0;
}