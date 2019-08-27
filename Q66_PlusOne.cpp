/*
* @Author: ShenZheng
* @Date:   2019-05-18 16:47:44
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-05-18 17:06:26
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int flag = 1;
        int i = size-1;
        while(i>=0 && flag==1)
        {
            if(digits[i]==9)
            {
                digits[i]=0;
            }
            else
            {
                flag=0;
                digits[i]++;
            }
            i--;
        }
        if(i<0 && flag==1)
        {
            digits[0]=1;
            digits.push_back(0);
        }
        return digits;
    }
};

int main(){
    vector<int> arr={9};
    vector<int> result = Solution().plusOne(arr);
    for(auto item:result)
        cout<<item<<" ";
    cout<<endl;
    return 0;
}