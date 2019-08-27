/*
* @Author: ShenZheng
* @Date:   2019-04-06 09:13:18
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-04-06 10:13:38
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        int LongestLen = 0;
        const int NumChar=256;
        vector<int> counter(NumChar,0);
        int curNum=0;
        int index=0;
        while(s[index]!='\0')
        {
            if(counter[s[index]]!=0)
            {
                //fill(counter.begin(),counter.end(),0);
                fill_n(counter.begin(),NumChar,0);
                counter[s[index]]=1;
                curNum=1;
            }
            else
            {
                counter[s[index]]=1;
                curNum++;
                LongestLen=max(LongestLen,curNum);
            }
            index++;
            cout<<curNum<<LongestLen<<endl;
        }
        return LongestLen;
    }
};

int lengthOfLongestSubstring(string s)
{
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
}

int main(){
    string str="dvdf";
    int result = Solution().lengthOfLongestSubstring(str);
    int result2 = lengthOfLongestSubstring(str);
    cout<<result2<<endl;
    return 0;
}

