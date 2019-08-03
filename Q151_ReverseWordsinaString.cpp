/*
* @Author: ShenZheng
* @Date:   2019-07-14 20:40:01
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-07-14 20:51:00
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        auto start = s.begin();
        auto end = s.end();


    }
};

int main(){
    string str="i am a iron man";
    string result = Solution().reverseWords(str);
    cout<<result<<endl;
    return 0;
}