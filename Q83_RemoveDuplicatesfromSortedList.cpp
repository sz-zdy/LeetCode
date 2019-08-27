/*
* @Author: ShenZheng
* @Date:   2019-05-23 15:04:11
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-05-23 15:11:43
*/

#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode* cur = head;
        while(cur->next!=NULL)
        {
            if(cur->next->val==cur->val)
                cur->next = cur->next->next;
            else
                cur=cur->next;
        }
        return head;
    }
};

int main(){

    return 0;
}