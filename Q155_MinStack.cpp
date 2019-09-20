/*
* @Author: anchen
* @Date:   2019-06-29 21:05:34
* @Last Modified by:   anchen
* @Last Modified time: 2019-06-29 21:12:34
*/

#include <iostream>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        NormalStack.push(x);
        int number = helperStack.empty()?x:(x<helperStack.top()?x:helperStack.top());
        helperStack.push(number);
    }

    void pop() {
        assert(!NormalStack.empty());
        NormalStack.pop();
        helperStack.pop();
    }

    int top() {
        assert(!NormalStack.empty());
        return NormalStack.top();
    }

    int getMin() {
        assert(!helperStack.empty());
        return helperStack.top();
    }
private:
    stack<int> NormalStack;
    stack<int> helperStack;
};

int main(){

    return 0;
}