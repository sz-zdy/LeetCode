/*
* @Author: ShenZheng
* @Date:   2019-06-25 16:42:18
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-25 17:01:03
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curProfit = 0;
        int maxProfit = 0;
        for(int i=1;i<prices.size();i++)
        {
            curProfit=max(0,curProfit+=prices[i]-prices[i-1]);
            maxProfit=maxProfit>curProfit?maxProfit:curProfit;
        }
        return maxProfit;
    }
};

int main(){

    return 0;
}