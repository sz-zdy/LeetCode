/*
* @Author: ShenZheng
* @Date:   2019-05-19 09:29:07
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-05-19 10:09:21
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int size = std::max(a.size(),b.size());
        a = string((size-a.size()),'0') + a;
        b = string((size-b.size()),'0') + b;
        string c(size,'0');
        int m = size-1;
        int flag = 0;
        while(m>=0)
        {
            if(flag==0)
            {
                if(a[m]=='1' && b[m]=='1')
                {
                    flag = 1;
                    c[m]='0';
                }
                else if(a[m]=='0' && b[m]=='0')
                {
                    flag = 0;
                    c[m]='0';
                }
                else
                {
                    flag = 0;
                    c[m]='1';
                }
            }
            else
            {
                if(a[m]=='1' && b[m]=='1')
                {
                    flag = 1;
                    c[m]='1';
                }
                else if(a[m]=='0' && b[m]=='0')
                {
                    flag = 0;
                    c[m]='1';
                }
                else
                {
                    flag = 1;
                    c[m]='0';
                }
            }
            m--;
        }
        if(flag==1)
            c="1"+c;
        return c;
    }
};

int main(){
    string result = Solution().addBinary("101","100");
    cout<<result<<endl;
    return 0;
}