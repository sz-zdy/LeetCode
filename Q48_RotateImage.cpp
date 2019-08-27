/*
* @Author: ShenZheng
* @Date:   2019-04-05 09:34:36
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-04-05 10:16:18
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        size_t n = matrix.size();
        if(n<=1)
            return ;

        unsigned LeftUp = 0;
        unsigned RightDown = n-1;
        while(LeftUp<=RightDown)
        {
            Core(matrix,LeftUp,RightDown);
            LeftUp++;RightDown--;
        }
    }
    void Core(vector<vector<int>>& matrix,unsigned lu,unsigned rd)
    {
        if(lu==rd)
            return ;
        for(unsigned i = 0; i < (rd-lu); i++)
        {
            int tmp = matrix[lu][lu+i];
            matrix[lu][lu+i] = matrix[rd-i][lu];
            matrix[rd-i][lu] = matrix[rd][rd-i];
            matrix[rd][rd-i] = matrix[lu+i][rd];
            matrix[lu+i][rd] = tmp;
        }
    }
};

int main(){
    vector<vector<int>> vec= {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    Solution().rotate(vec);
    for(auto item:vec)
    {
        for(auto item2:item)
        {
            cout<<item2<<" ";
        }
        cout<<endl;
    }

    return 0;
}