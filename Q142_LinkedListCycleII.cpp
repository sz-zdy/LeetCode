/*
* @Author: ShenZheng
* @Date:   2019-06-27 10:34:29
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-27 10:36:24
*/

#include <iostream>

using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fastptr=head;
        ListNode* slowptr=head;
        while(fastptr!=NULL)
        {
            fastptr=fastptr->next;
            if(fastptr==NULL)
                return NULL;
            else
                fastptr=fastptr->next;
            slowptr=slowptr->next;
            if(fastptr==slowptr) break;
        }
        if(fastptr==NULL)
            return NULL;

        fastptr=head;
        while(fastptr!=slowptr)
        {
            fastptr=fastptr->next;
            slowptr=slowptr->next;
        }
        return fastptr;
    }
};

int main(){

    return 0;
}