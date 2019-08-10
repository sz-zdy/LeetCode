/*
 * @Description: 
 * @Autor: shenzheng
 * @email: sznust@163.com
 * @Date: 2019-08-10 12:55:15
 * @LastEditors: shenzheng
 * @LastEditTime: 2019-08-10 13:04:26
 */


// Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *helpNode = new ListNode(0);
        ListNode *tmp;
        while(head != nullptr){
            tmp = head->next;
            head->next = helpNode->next;
            helpNode->next = head;
            head = tmp;
        }
        return (helpNode->next); 
    }
};