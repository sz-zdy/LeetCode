/*
* @Author: ShenZheng
* @Date:   2019-09-02 21:19:52
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-09-02 21:30:09
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode *fastPtr = head->next;
        ListNode *slowPtr = head;
        while(fastPtr != slowPtr && fastPtr != nullptr){
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
            if(fastPtr == nullptr)
                return false;
            else
                fastPtr = fastPtr->next;
        }

        if(fastPtr == nullptr)
            return false;
        return true;
    }
};

int main(){

    return 0;
}