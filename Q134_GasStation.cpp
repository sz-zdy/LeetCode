/*
* @Author: ShenZheng
* @Date:   2019-06-26 15:10:00
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-26 16:46:15
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int StationNum = gas.size();
        vector<int> diff(StationNum,0);
        for(int i=0;i<StationNum;i++)
        {
            diff[i]=gas[i]-cost[i];
        }
        int startindex = 0;
        int index = (startindex+1)%StationNum;
        int tmp = diff[startindex];
        while(startindex<StationNum && index!=startindex)
        {
            cout<<startindex<<" "<<tmp<<" "<<index<<endl;
            if(tmp<0)
            {
                while((++startindex)<StationNum && diff[startindex]<0) ;
                if(startindex>=StationNum) break;
                tmp=diff[startindex];
                index=(startindex+1)%StationNum;
            }
            else
            {
                tmp+=diff[index];
                index=(index+1)%StationNum;
            }
        }
        if(startindex>=StationNum || tmp<0)
            return -1;
        else
            return startindex;
    }
};



int main(){
    vector<int> gas={1,2,3,4,3,2,4,1,5,3,2,4};
    vector<int> cost={1,1,1,3,2,4,3,6,7,4,3,1};
    int result = Solution().canCompleteCircuit(gas,cost);
    cout<<result<<endl;
    return 0;
}