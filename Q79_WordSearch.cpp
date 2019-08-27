/*
* @Author: ShenZheng
* @Date:   2019-05-21 14:17:08
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-05-21 15:27:21
*/

#include <iostream>
#include <vector>
using namespace std;

/*
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> flag(m,vector<bool> (n,false));
        bool result =false;
        for(int i = 0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(Core(i,j,board,word,0,flag))
                    return true;
            }
        }
        return result;
    }

    bool Core( int i, int j, vector<vector<char>>& board, string word, int k, vector<vector<bool>> flag)
    {
        if(k>=word.size())
            return true;

        int m = board.size();
        int n = board[0].size();
        if(i<0 || i>=m || j<0 || j>=n || flag[i][j]==true || board[i][j]!=word[k])
            return false;

        flag[i][j]=true;
        bool tmp = Core(i-1,j,board,word,k+1,flag) || Core(i+1,j,board,word,k+1,flag) || Core(i,j-1,board,word,k+1,flag) || Core(i,j+1,board,word,k+1,flag);
        if(tmp)
            return true;
        else
            return false;
    }
};
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        bool result =false;
        for(int i = 0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(Core(i,j,board,word,0))
                    return true;
            }
        }
        return result;
    }

    bool Core( int i, int j, vector<vector<char>>& board, string word, int k)
    {
        if(k>=word.size())
            return true;

        int m = board.size();
        int n = board[0].size();
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]=='*' || board[i][j]!=word[k])
            return false;

        char store = board[i][j];
        board[i][j]='*';
        bool tmp = Core(i-1,j,board,word,k+1) || Core(i+1,j,board,word,k+1) || Core(i,j-1,board,word,k+1) || Core(i,j+1,board,word,k+1);
        if(tmp)
            return true;
        else
        {
            board[i][j] = store;
            return false;
        }
    }
};

int main(){
    vector<vector<char>> board ={
      {'A','B','C','E'},
      {'S','F','C','S'},
      {'A','D','E','E'}
    };
    string word = "SEE";
    bool result = Solution().exist(board,word);
    cout<<result<<endl;
    return 0;
}