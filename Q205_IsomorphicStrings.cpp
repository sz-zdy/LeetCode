/*
 * @Description: 
 * @Autor: shenzheng
 * @email: sznust@163.com
 * @Date: 2019-08-09 23:27:21
 * @LastEditors: shenzheng
 * @LastEditTime: 2019-08-10 12:42:43
 */
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// My silly solution, very slow and use too much memory
class Solution1 {
public:
    bool isIsomorphic(string s, string t) {
        map<char,vector<int>> myMap1;
        map<char,vector<int>> myMap2;
        for(int i = 0; i<s.size(); i++){
            auto it1 = myMap1.find(s[i]); 
            if(it1 == myMap1.end()){
                myMap1[s[i]] = vector<int>();
            }
            myMap1[s[i]].push_back(i); 
            auto it2 = myMap2.find(t[i]); 
            if(it2 == myMap2.end()){
                myMap2[t[i]] = vector<int>();
            }
            myMap2[t[i]].push_back(i);   
        }
        map<int,vector<int>> Map1;
        map<int,vector<int>> Map2;
        for(auto it = myMap1.begin(); it != myMap1.end(); it++){
            Map1.insert(make_pair((it->second)[0],it->second));
        }
        for(auto it = myMap2.begin(); it != myMap2.end(); it++){
            Map2.insert(make_pair((it->second)[0],it->second));
        }
        return (Map1==Map2); 
    }
};

// Other's Solution
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> charMapS;
        map<char,char> charMapT;
        int chrLen = s.size();
        for(int i = 0; i < chrLen; i++){
            if(charMapS.find(s[i])!=charMapS.end()){
                if(charMapS[s[i]] != t[i]){
                    return false;
                }else{}
            }else{
                if(charMapT.find(t[i])!=charMapT.end())
                    return false;
                charMapS.insert(make_pair(s[i],t[i]));
                charMapT.insert(make_pair(t[i],s[i]));
                }
        }
        return true;
    }
};

int main(){
    string s = "addhabs";
    string t = "bnnfbbe";
    bool result = Solution().isIsomorphic(s,t);
    cout<<result<<endl;
    return 0;
}