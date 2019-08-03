#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
class Solution {
public:
    int titleToNumber(string s) {
        const int AlphabetNum = 26;
        unsigned int result = 0;
        for(char& ch:s){
            result = result * AlphabetNum + ch - 'A' + 1;
        }
        return result;
    }
};


int main()
{
    string str = "AB";
    int result = Solution().titleToNumber(str);
    cout<< result << endl;
    return 0;
}