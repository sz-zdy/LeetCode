/*
* @Author: ShenZheng
* @Date:   2019-09-02 14:25:13
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-09-02 14:33:52
*/

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode *newHead = new ListNode(0);
        ListNode *tmp = new ListNode(0);
        while(head!=nullptr){
            tmp = head->next;
            head->next = newHead->next;
            newHead->next = head;
            head = tmp;
        }
        delete tmp;
        return newHead;
    }
};

int main(){

    return 0;
}