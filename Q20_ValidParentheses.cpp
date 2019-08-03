/*
* @Author: ShenZheng
* @Date:   2018-11-01 21:15:55
* @Last Modified by:   ShenZheng
* @Last Modified time: 2018-11-01 21:52:06
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> s_c;
    s_c.push(' ');
    for(auto c:s)
    {
          switch(c)
          {
            case ')': s_c.top()=='('?s_c.pop():s_c.push(c);break;
            case ']': s_c.top()=='['?s_c.pop():s_c.push(c);break;
            case '}': s_c.top()=='{'?s_c.pop():s_c.push(c);break;
            default:s_c.push(c);
          }
    }
    return s_c.empty()==' ';
}

int main(){
    cout<<isValid("]")<<endl;
    return 0;
}