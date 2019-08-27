/*
* @Author: ShenZheng
* @Date:   2019-05-19 20:31:11
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-05-19 21:51:21
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
    /*
    string simplifyPath(string path) {
        int size = path.size();
        if(size==0 || path[0]!='/')
            return path;
        vector<string> splitstr;
        int index = 0;
        int startindex = index;
        int count = 0;
        while(index<size)
        {
            if(path[index]=='/')
            {
                if(count>0)
                {
                    splitstr.push_back(path.substr(startindex,count));
                }
                startindex=index+1;
                count=0;
            }
            else
            {
                count++;
            }
            index++;
        }
        if(count>0)
            splitstr.push_back(path.substr(startindex,count));

        for(auto item:splitstr)
            cout<<item<<" ";
        cout<<endl;
        stack<string> tmp;
        for(auto item:splitstr)
        {
            if(item=="..")
            {
                if(!tmp.empty())
                {
                    tmp.pop();
                }
            }
            else if(item!=".")
            {
                tmp.push(item);
            }
        }
        //cout<<tmp.size()<<endl;
        string result = "";
        while(!tmp.empty())
        {
            //cout<<tmp.top()<<endl;
            result = tmp.top() + "/" + result;
            tmp.pop();
        }
        if(result.empty())
            result="/";
        else
            result = result.substr(result.size()-1,1) + result.substr(0,result.size()-1);
        return result;
    }
*/
    string simplifyPath(string path)
    {
        string res, tmp;
        vector<string> stk;
        stringstream ss(path);      //可以近似的实现split的方法
        while(getline(ss,tmp,'/'))
        {
            if (tmp == "" or tmp == ".") continue;
            if (tmp == ".." and !stk.empty()) stk.pop_back();
            else if (tmp != "..") stk.push_back(tmp);
        }
        for(auto str : stk) res += "/"+str;
        return res.empty() ? "/" : res;
    }

};

int main(){
    string path1 = "/a//b////c/d//././/..";
    string result = Solution().simplifyPath(path1);
    cout<<result<<endl;
    return 0;
}