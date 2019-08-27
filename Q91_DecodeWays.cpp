/*
* @Author: ShenZheng
* @Date:   2019-06-17 15:52:59
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-17 21:13:20
*/

#include <iostream>

using namespace std;

//方法1：递归超时
/*
class Solution {
public:
    int numDecodings(string s) {
        return helper(s);
    }
    int helper(string s)
    {
        if(s.empty() || (s.size()==1 && s[0]!='0'))
            return 1;
        else if(s[0]=='0')
            return 0;

        int counter = 0;
        int number=s[0]-'0';
        counter=helper(s.substr(1));
        number=number*10+s[1]-'0';
        if(number>=1 && number<=26)
            counter+=helper(s.substr(2));
        return counter;
    }
};
*/

//方法2：for循环
class Solution {
public:
    int numDecodings(string s) {
        int length = s.size();
        if(length==0)
            return 0;
        int* arr=new int[length+1];
        arr[length]=1;
        int index=length-1;
        if(s[index]=='0')
            arr[index]=0;
        else
            arr[index]=1;
        if(length==1)
            return arr[0];
        index--;

        while(index>=0)
        {
            if(s[index]=='0')
                arr[index]=0;
            else
            {
                if((s[index]-'0')*10+s[index+1]-'0'<=26)
                    arr[index]=arr[index+1]+arr[index+2];
                else
                    arr[index]=arr[index+1];
            }
            index--;
        }
        int result=arr[0];
        delete[] arr;
        return result;
    }
};
int main(){
    string str="36";
    int result = Solution().numDecodings(str);
    cout<<result<<endl;
    return 0;
}