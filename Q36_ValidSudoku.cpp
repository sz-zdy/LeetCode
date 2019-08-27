/*
* @Author: ShenZheng
* @Date:   2019-04-09 14:33:50
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-04-09 15:49:07
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int size=board.size();
        vector<bool> counter1(size,0);
        vector<bool> counter2(size,0);
        for(int i=0;i<size;i++)
        {
            fill_n(counter1.begin(),size,false);
            fill_n(counter2.begin(),size,false);
            for(int j=0;j<size;j++)
            {
                if(isdigit(board[i][j]))
                {
                    if(counter1[board[i][j]-'1'])
                        return false;
                    else
                        counter1[board[i][j]-'1']=true;
                }

                if(isdigit(board[j][i]))
                {
                    if(counter2[board[j][i]-'1'])
                        return false;
                    else
                        counter2[board[j][i]-'1']=true;
                }
            }
        }

        //判断每一个小正方形的情况
        for(int i=0;i<9;i=i+3)
        {
            for(int j=0;j<9;j=j+3)
            {
                fill_n(counter1.begin(),size,false);
                for(int i1=0;i1<3;i1++)
                {
                    for(int j1=0;j1<3;j1++)
                    {
                        if(isdigit(board[i+i1][j+j1]))
                        {
                            if(counter1[board[i+i1][j+j1]-'1'])
                                return false;
                            else
                                counter1[board[i+i1][j+j1]-'1']=true;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main(){
    vector<vector<char>> example1={
  {'5','3','.','.','7','.','.','.','.'},
  {'6','.','.','1','9','5','.','.','.'},
  {'.','9','8','.','.','.','.','6','.'},
  {'8','.','.','.','6','.','.','.','3'},
  {'4','.','.','8','.','3','.','.','1'},
  {'7','.','.','.','2','.','.','.','6'},
  {'.','6','.','.','.','.','2','8','.'},
  {'.','.','.','4','1','9','.','.','5'},
  {'.','.','.','.','8','.','.','7','9'}
    };

    vector<vector<char>> example2={
  {'8','3','.','.','7','.','.','.','.'},
  {'6','.','.','1','9','5','.','.','.'},
  {'.','9','8','.','.','.','.','6','.'},
  {'8','.','.','.','6','.','.','.','3'},
  {'4','.','.','8','.','3','.','.','1'},
  {'7','.','.','.','2','.','.','.','6'},
  {'.','6','.','.','.','.','2','8','.'},
  {'.','.','.','4','1','9','.','.','5'},
  {'.','.','.','.','8','.','.','7','9'}
    };

    bool result1=Solution().isValidSudoku(example1);
    cout<<result1<<endl;
    bool result2=Solution().isValidSudoku(example2);
    cout<<result2<<endl;
    return 0;
}