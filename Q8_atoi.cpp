/*
* @Author: ShenZheng
* @Date:   2018-10-22 20:22:26
* @Last Modified by:   ShenZheng
* @Last Modified time: 2018-10-22 20:49:42
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        bool flag=false;
        int result=0;
        for(char c:str)
        {
            if(c!=' ')
            {
                result=result*10+(c-'0');
            }
            else
            {
                if(result!=0)
                    return
            }
        }
        return result;
    }
};


int main(){
    string str1="42";
    string str2="   -42";
    string str3="4193 with words";
    string str4="words and 987";
    string str5="-91283472332";
    Solution s1;

    cout<<"1st: "<<s1.myAtoi(str1)<<endl;
/*    cout<<"2nd: "<<s1.myAtoi(str2)<<endl;
    cout<<"3th: "<<s1.myAtoi(str3)<<endl;
    cout<<"4th: "<<s1.myAtoi(str4)<<endl;
    cout<<"5th: "<<s1.myAtoi(str5)<<endl;
*/
    return 0;
}