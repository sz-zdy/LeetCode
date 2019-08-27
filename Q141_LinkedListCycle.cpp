/*
* @Author: ShenZheng
* @Date:   2019-06-27 10:17:39
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-27 10:33:34
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int hasCycle(ListNode *head) {
        ListNode* fastptr=head;
        ListNode* slowptr=head;
        while(fastptr!=NULL)
        {
            fastptr=fastptr->next;
            if(fastptr==NULL)
                return -1;
            else
                fastptr=fastptr->next;
            slowptr=slowptr->next;
            if(fastptr==slowptr) break;
        }
        if(fastptr==NULL)
            return -1;

        int pos = 0;
        fastptr=head;
        while(fastptr!=slowptr)
        {
            fastptr=fastptr->next;
            slowptr=slowptr->next;
            pos++;
        }
        return pos;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fastptr=head;
        ListNode* slowptr=head;
        while(fastptr!=NULL)
        {
            fastptr=fastptr->next;
            if(fastptr==NULL)
                return false;
            else
                fastptr=fastptr->next;
            slowptr=slowptr->next;
            if(fastptr==slowptr) break;
        }
        if(fastptr==NULL)
            return false;
        else
            return true;
    }
};

int main(){

    return 0;
}