/*
* @Author: anchen
* @Date:   2019-06-29 21:22:16
* @Last Modified by:   anchen
* @Last Modified time: 2019-06-29 21:26:17
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        for(int i=0;i<32;i++)
        {
            if(n>>i & 1)
                result++;
        }
        return result;
    }
};

int main(){

    return 0;
}