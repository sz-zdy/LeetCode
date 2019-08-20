/*
 * @Description: medium
 * @Autor: shenzheng
 * @email: sznust@163.com
 * @Date: 2019-08-21 00:05:20
 * @LastEditors: shenzheng
 * @LastEditTime: 2019-08-21 00:18:44
 */

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int sz = 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!i || !j || matrix[i][j]=='0')
                    dp[i][j] = matrix[i][j] - '0';
                else{
                    dp[i][j] = min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1])+1;
                }
                sz = max(sz,dp[i][j]);
            }
        }
        return sz*sz;
    }
};
