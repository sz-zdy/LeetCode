/*
* @Author: ShenZheng
* @Date:   2018-11-12 20:45:03
* @Last Modified by:   ShenZheng
* @Last Modified time: 2018-11-12 21:21:56
*/

#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int number=nums.size();

    return 0;
}

int main(){
    vector<int> arr;
    for(int i=0;i<100;i++)
        arr.push_back(i/8);
    for(auto t:arr)
        cout<<t<<" "<<endl;
    removeElement(arr,5);
    return 0;
}