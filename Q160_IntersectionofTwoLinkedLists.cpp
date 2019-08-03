/*
* @Author: ShenZheng
* @Date:   2019-07-14 20:53:07
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-08-03 09:56:18
*/

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        int ListALen = 1, listBLen = 1;
        while(l1->next!=NULL)
        {
            l1 = l1->next;
            ListALen++;
        }
        while(l2->next!=NULL)
        {
            l2 = l2->next;
            ListBLen++;
        }
        ListNode* result = NULL;
        if(l1==l2)
        {
            l1 = headA;
            l2 = headB;
            if(ListALen>ListBLen)
            {
                for(int i = 0; i<ListALen-ListBLen;i++) l1=l1->next;
            }
            else
            {
                for(int i = 0; i<ListBLen-ListALen;i++) l2=l2->next;
            }
            while(l1!=l2)
            {
                l1 = l1->next;
                l2 = l2->next;
            }
            result = l1;
        }
        return result;
    }
};

int main(){

    return 0;
}