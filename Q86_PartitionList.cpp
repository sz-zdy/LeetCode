/*
* @Author: ShenZheng
* @Date:   2019-05-23 15:13:34
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-05-23 21:01:08
*/

#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL)
            return NULL;
        ListNode* head1 = NULL;
        ListNode* head2 = NULL;
        ListNode* cur1=NULL;
        ListNode* cur2=NULL;
        ListNode* cur=head;
        while(cur!=NULL)
        {
            if(cur->val>=x)
            {
                if(head2==NULL)
                {
                    head2=cur;
                    cur2=head2;
                }
                else
                {
                    cur2->next
                }
            }
            else
            {
                if()
            }
        }
    }
};

int main(){

    return 0;
}