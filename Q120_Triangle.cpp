/*
 * @Description: Triangle
 * @Autor: shenzheng
 * @email: sznust@163.com
 * @Date: 2019-08-22 23:11:13
 * @LastEditors: shenzheng
 * @LastEditTime: 2019-08-22 23:21:18
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())
            return 0;
        int row = triangle.size();
        int maxCol = triangle[row-1].size();

        for(int i = row-2; i >= 0; i--){
            for(int j = 0; j < triangle[i].size(); j++){
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};