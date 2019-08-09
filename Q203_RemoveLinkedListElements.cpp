/*
 * @Description: 
 * @Autor: shenzheng
 * @email: sznust@163.com
 * @Date: 2019-08-09 21:52:33
 * @LastEditors: shenzheng
 * @LastEditTime: 2019-08-09 22:01:46
 */


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* HHead = new ListNode(0);
        HHead->next = head;
        ListNode* slowPtr = HHead;
        ListNode* fastPtr = HHead;
        while(fastPtr!=nullptr){
            if(fastPtr->val == val){
                slowPtr->next = fastPtr->next;
                fastPtr = fastPtr->next;
            }else{
                slowPtr = fastPtr;
                fastPtr = fastPtr->next;
            }
        }
        return (HHead->next);
    }
};