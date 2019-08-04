/*
 * @Description: 
 * @Autor: shenzheng
 * @email: sznust@163.com
 * @Date: 2019-08-04 15:44:44
 * @LastEditors: shenzheng
 * @LastEditTime: 2019-08-04 15:58:12
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int column = grid[0].size();
        if(column == 0) return 0;
        int counter = 0;
        for(int i = 0; i<row; i++){
            for(int j = 0; j<column; j++){
                if(grid[i][j] != '1') continue;
                counter++;
                DFS(i,j,row,column,grid);
            }
        }
        return counter;
    }
private:
    void DFS(int i, int j, int row, int column, vector<vector<char>>& grid){
        if(i<0 || i>=row || j<0 || j>= column)
            return ;
        if(grid[i][j]=='1'){
            grid[i][j]='2';
            DFS(i-1,j,row,column,grid);
            DFS(i+1,j,row,column,grid);
            DFS(i,j-1,row,column,grid);
            DFS(i,j+1,row,column,grid);
        }
    }
};