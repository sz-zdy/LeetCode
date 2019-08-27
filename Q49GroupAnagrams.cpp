/*
* @Author: ShenZheng
* @Date:   2019-04-04 14:40:33
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-04-04 14:55:59
*/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        multimap<string,string> mmp;
        for(auto item:strs)
        {
            string tmp = item;
            sort(tmp.begin(),tmp.end());
            mmp.insert(make_pair(tmp,item));
        }
        //遍历，同一个就放在一个组里
        for(auto it=mmp.begin();it!=mmp.end();it=mmp.upper_bound(it->first))
        {
            vector<string> tmpVecStr;
            auto range = mmp.equal_range(it->first);
            for(auto it2=range.first;it2!=range.second;it2++)
            {
                tmpVecStr.push_back(it2->second);
            }
            result.push_back(tmpVecStr);
        }
        return result;
    }
};

//leetcode 优秀解答
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> container;
        for(auto item:strs)
        {
            string tmp = item;
            sort(tmp.begin(),tmp.end());
            container[tmp].push_back(item);
        }
        //遍历，同一个就放在一个组里
        for(auto it=container.begin();it!=container.end();it++)
        {
            result.push_back(it->second);
        }
        return result;
    }
};