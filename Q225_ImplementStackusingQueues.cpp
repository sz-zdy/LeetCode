/*
 * @Description: Implement Stack using Queues
 * @Autor: shenzheng
 * @email: sznust@163.com
 * @Date: 2019-08-21 22:09:05
 * @LastEditors: shenzheng
 * @LastEditTime: 2019-08-21 22:31:25
 */

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        for(int i = 0; i < que.size()-1; i++){
            que.push(que.front());
            que.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int topElement = que.front();
        que.pop();
        return topElement;
    }
    
    /** Get the top element. */
    int top() {
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
private:
    queue<int> que;
};