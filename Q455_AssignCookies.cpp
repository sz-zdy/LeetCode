/*
* @Author: ShenZheng
* @Date:   2019-09-09 14:37:29
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-09-10 08:25:56
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//贪心策略
//方法1：自己写的，find_if的使用有一些冗余
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //g : gread factor
        //s : cookie size

        if(g.empty() || s.empty()) return 0;

        int result = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        auto it_g = g.begin();
        auto it_s = s.begin();
        for(;it_g != g.end(); it_g++){
            it_s = find_if(it_s, s.end(), [it_g](int size)->bool{return (*it_g <= size);});
            if(it_s != s.end()){
                result ++;
                it_s++;
            }
            else
                return result;
        }

        return result;
    }
};

class Solution2 {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //g : gread factor
        //s : cookie size
        if(g.empty() || s.empty()) return 0;

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int result = 0;
        int i = 0;       //i: index for g
        int j = 0;       //j: index for s

        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){
                i++; j++;
                result++;
            }else if(g[i] > s[j]){
                j++;
            }
        }
        return result;
    }
};
int main(){
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};
    int result = Solution2().findContentChildren(g,s);
    cout<<result<<endl;
    return 0;
}