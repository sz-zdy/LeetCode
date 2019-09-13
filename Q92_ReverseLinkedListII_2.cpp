/*
* @Author: ShenZheng
* @Date:   2019-09-02 15:22:23
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-09-02 16:15:02
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Do it in one-pass.
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *helpHead = new ListNode(0);
        helpHead->next = head;

        ListNode *pre = helpHead;
        for(int i = 1; i < m; i++){
            head = head->next;
            pre = pre->next;
        }

        ListNode *tmp = nullptr;
        ListNode *lastNode = head;
        for(int i = m; i <= n ; i++){
            tmp = head->next;
            head->next = pre->next;
            pre->next = head;
            head = tmp;
        }
        lastNode->next = head;
        return (helpHead->next);
    }
};

int main(){

    return 0;
}