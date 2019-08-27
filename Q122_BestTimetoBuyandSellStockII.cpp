/*
* @Author: ShenZheng
* @Date:   2019-06-25 17:04:24
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-25 17:09:28
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int diff = 0;
        for(int i=1;i<prices.size();i++)
        {
            diff = prices[i]-prices[i-1];
            maxProfit += (diff>0?diff:0);
        }
        return maxProfit;
    }
};

int main(){

    return 0;
}