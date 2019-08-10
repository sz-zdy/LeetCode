/*
 * @Description: 
 * @Autor: shenzheng
 * @email: sznust@163.com
 * @Date: 2019-08-09 22:05:49
 * @LastEditors: shenzheng
 * @LastEditTime: 2019-08-09 23:05:59
 */

#include <iostream>
#include <vector>
using namespace std;

// My own silly solution 
class Solution1 {
public:
    int countPrimes(int n) {
       if(n==0 || n==1) return 0;
       if(n==2 || n==3) return (n-2);
       int counter = 2;
       for(int i = 4; i < n; i++){
            if(isPrime(i)){
                counter++;
                cout<<i<<" ";
            }
       }
       return counter;
    }
private:
    bool isPrime(int num){
        for(int i = 2; i<=(num/2)+1; i++){
            if(num%i == 0)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1) return 0;
        if(n==2 || n==3) return (n-2);
        vector<bool> flag(n,true);
        int counter = 0;
        for(int i = 2; i<n; i++){
            if(flag[i])
                counter++;
            for(int j = 2;i*j < n; j++){
                flag[i*j] = false;
            }
        }
        return counter;
    }
};

int main()
{
    int num = 11;
    int result = Solution().countPrimes(num);
    cout<< result << endl;
    return 0;
}