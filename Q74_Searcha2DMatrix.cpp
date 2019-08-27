/*
* @Author: ShenZheng
* @Date:   2019-05-20 16:57:41
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-05-20 17:15:47
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int beg = 0;
        int end = m*n-1;
        int mid;
        int val;
        while(beg<=end)
        {
            mid=(beg+end)/2;
            val=matrix[mid/n][mid%n];
            if(val<target)
            {
                beg=mid+1;
            }
            else if(val>target)
                end=mid-1;
            else
                return true;
        }
        return false;
    }
};

int main(){
    vector<vector<int>> matrix = {
      {1,   3,  5,  7},
      {10, 11, 16, 20},
      {23, 30, 34, 50}
    };
    int target = 34;
    bool result = Solution().searchMatrix(matrix,target);
    cout<<result<<endl;
    return 0;
}