/*
* @Author: ShenZheng
* @Date:   2019-06-25 17:13:34
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-25 17:31:41
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j = s.size() - 1;
        while(i<j)
        {
            while(i<j && !isalnum(s[i])) i++;
            while(i<j && !isalnum(s[j])) j--;
            if(i<j && tolower(s[i])!=tolower(s[j]))
                return false;
            i++;j--;
        }
        return true;
    }
};

int main(){
    string s = "0P";
    cout<<(Solution().isPalindrome(s))<<endl;
    return 0;
}