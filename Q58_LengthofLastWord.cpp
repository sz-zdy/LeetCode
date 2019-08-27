/*
* @Author: ShenZheng
* @Date:   2019-05-04 20:48:14
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-05-04 21:15:02
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size();
        int result = 0;
        if(size>0)
        {
            for(int i=size-1;i>=0;i--)
            {
                if(isalpha(s[i]))
                {
                    result++;
                }
                else if(result>0)
                {
                    break;
                }
            }
        }
        return result;
    }
};

int main(){
    string s = "a ";
    int result = Solution().lengthOfLastWord(s);
    cout<<result<<endl;
    return 0;
}