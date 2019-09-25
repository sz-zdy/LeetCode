class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
            return n;
        int preOne = 2;
        int preTwo = 1;
        int result;
        for(int i = 3; i <= n; i++){
            result = preTwo + preOne;
            preTwo = preOne;
            preOne = result;
        }
        return result;
    }
};