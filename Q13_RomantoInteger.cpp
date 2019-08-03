/*
* @Author: ShenZheng
* @Date:   2018-10-22 20:53:48
* @Last Modified by:   ShenZheng
* @Last Modified time: 2018-10-22 21:32:23
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int str_size=s.size();
        cout<<str_size<<endl;
        int now,behind;
        int result=0;
        for(int i=str_size-1;i>=0;i--)
        {
            switch(s[i])
            {
                case 'I': now=1;break;
                case 'V': now=5;break;
                case 'X': now=10;break;
                case 'L': now=50;break;
                case 'C': now=100;break;
                case 'D': now=500;break;
                case 'M': now=1000;break;
                default: break;
            }
            if(i==str_size-1)
                result=now;
            else if (now<behind)
                result=result-now;
            else
                result=result+now;
            behind=now;
        }
        return result;
    }
};

int main(){
    string str1="III";
    string str2="IV";
    string str3="IX";
    string str4="LVIII";
    string str5="MCMXCIV";
    Solution s1;
    cout<<"1st: "<<s1.romanToInt(str1)<<endl;
    cout<<"2nd: "<<s1.romanToInt(str2)<<endl;
    cout<<"3th: "<<s1.romanToInt(str3)<<endl;
    cout<<"4th: "<<s1.romanToInt(str4)<<endl;
    cout<<"5th: "<<s1.romanToInt(str5)<<endl;
    return 0;
}