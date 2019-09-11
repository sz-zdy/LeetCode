/*
* @Author: ShenZheng
* @Date:   2019-09-11 08:32:36
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-09-11 14:30:32
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution1 {
public:
    string removeKdigits(string num, int k) {
        stack<char> sta;
        sta.push(num[0]);
        for(int i = 1; i < num.size(); i++){
            while(!sta.empty() && num[i] < sta.top() && k > 0){
                sta.pop();
                k--;
            }
            if(!(sta.empty() && num[i] == '0'))
                sta.push(num[i]);
        }
        string result = "";
        while(!sta.empty()){
            result = sta.top() + result;
            sta.pop();
        }
        result = result.substr(0,result.size()-k);
        return (result=="" ? "0":result);
    }
};

class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        for(int i = 0; i < num.size(); i++){
            while(result.size()>0 && num[i] < result.back() && k > 0){
                result.pop_back();
                k--;
            }
            if(!(result.empty() && num[i]=='0')){
                result.push_back(num[i]);
            }
            cout<<result<<endl;
        }
        result = result.substr(0,result.size()-k);
        return (result==""?"0":result);
    }
};

int main(){
    string num = "10200";
    int k = 1;
    string result = Solution().removeKdigits(num,k);
    cout<<result<<endl;
    return 0;
}