/*
 * @Description: 
 * @Autor: shenzheng
 * @email: sznust@163.com
 * @Date: 2019-08-09 21:02:49
 * @LastEditors: shenzheng
 * @LastEditTime: 2019-08-09 21:27:46
 */

// My own solution 
class Solution {
public:
    bool isHappy(int n) {
        int bitNum = 0, num = n;
        while(num){
            bitNum++;
            num /=10;
        }
        int i = 0;
        for(;i<bitNum*9*9;i++){
            n = getBitSqrSum(n);
            if(n==1)
                break;
        }
        return (i<bitNum*9*9);
    }
private:
    int getBitSqrSum(int num){
        int result = 0;
        while(num){
            result += (num%10) * (num%10);
            num = num / 10;
        }
        return result;
    }
};

//Other's solution in leetcode
    int digitSquareSum(int n) {
        int sum = 0, tmp;
        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
            if(fast == 1) return 1;
        } while(slow != fast);
    return 0;
}